struct manacher {
    vector<int> p;

    void run_manacher(string s) {
        int n = s.length();
        p.assign(n, 1);
        int l = 1, r = 1;
        for (int i = 1; i < n; i++) {
            int val = l + r - i;
            if(val < n && val >= 0)    p[i] = max(0, min(r - i, p[val]));
            while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]) 
                p[i]++;
            
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    void build(string s) {
        string t = "#";
        for (auto ele : s) {
            t += ele;
            t += "#";
        }
        run_manacher(t);
    }

    int getLongest(int cen, bool odd) {
        int pos = 2 * cen + 1 + (!odd);
        return p[pos] - 1;
    }

    bool checkPalin(int l, int r) {
        return (r - l + 1) <= getLongest((l + r) / 2, (l % 2 == r % 2));
    }
} man;

class Solution {
public:
    vector<int> sizes;  // Array to store sizes of nodes
    string dfsString;   // Store dfs string globally to avoid large concatenations

    void dfs(int node, vector<vector<int>> &graph, string &s) {
        sizes[node] = 1;  // Initialize size for the current node
        for (int child : graph[node]) {
            dfs(child, graph, s);
            sizes[node] += sizes[child];  // Add the size of the subtree rooted at child
        }
        dfsString += s[node];  // Append the character at node to the global dfsString
    }

    void traverse(int node, int l, int r, vector<vector<int>> &graph, vector<bool> &isPalindrome) {
        if (man.checkPalin(l, r)) {
            isPalindrome[node] = true;
        }

        int pre = 0;
        for (int child : graph[node]) {
            traverse(child, l + pre, l + pre + sizes[child] - 1, graph, isPalindrome);
            pre += sizes[child];
        }
    }

    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> graph(n, vector<int>());
        sizes.resize(n);  // Resize the sizes array to accommodate n nodes

        // Build the graph
        for (int i = 1; i < n; i++) {
            graph[parent[i]].push_back(i);
        }

        // Sort children in increasing order
        for (int i = 0; i < n; i++) {
            sort(graph[i].begin(), graph[i].end());
        }

        dfsString = "";  // Reset the global dfs string
        dfs(0, graph, s);  // Perform DFS to populate dfsString and subtree sizes

        // Build the palindrome helper with the global dfs string
        man.build(dfsString);

        vector<bool> isPalindrome(n, false);  // Store the result

        // Traverse and check palindromes for each node
        traverse(0, 0, dfsString.size() - 1, graph, isPalindrome);

        return isPalindrome;
    }
};
