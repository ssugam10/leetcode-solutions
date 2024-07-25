class Solution {
public:
    vector<vector<int>> adj;
    vector<long long> price;
    vector<long long> dp; // holds the maximum subtree sum of a particular root
    long long ans;

    long long pathWeight(int node, int parent) {
        long long mx = 0;
        for (auto neigh : adj[node]) {
            if (neigh == parent) continue;
            mx = max(mx, pathWeight(neigh, node));
        }
        return dp[node] = mx + price[node];
    }

    void dfs(int node, int parent, long long parentContribution) {
        long long child1 = 0, child2 = 0;
        int maxChildVal = -1;

        for (auto neigh : adj[node]) {
            if (neigh == parent) continue;

            if (dp[neigh] > child2) {
                child2 = dp[neigh];
                if (child2 > child1) {
                    swap(child2, child1);
                    maxChildVal = neigh;
                }
            }
        }

        ans = max({ans, child1, parentContribution});

        for (auto neigh : adj[node]) {
            if (neigh == parent) continue;

            if (neigh == maxChildVal) {
                dfs(neigh, node, price[node] + max(child2, parentContribution));
            } else {
                dfs(neigh, node, price[node] + max(child1, parentContribution));
            }
        }
    }

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        adj.clear();
        adj.resize(n);
        
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        this->price.resize(n);
        for (int i = 0; i < n; ++i) {
            this->price[i] = static_cast<long long>(price[i]);
        }
        
        dp.resize(n, 0);
        ans = LLONG_MIN;

        pathWeight(0, -1);
        dfs(0, -1, 0);

        return ans;
    }
};
