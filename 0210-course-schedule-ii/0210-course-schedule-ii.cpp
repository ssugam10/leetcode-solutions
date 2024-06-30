class Solution {
public:
    vector<list<int>> graph; // Adjacency list representation of the graph
    int v;  // Number of vertices
    unordered_set<int> visited; // Visited set to keep track of visited nodes
    vector<int> order; // To store the topological order

    Solution() : v(0) {}

    void add_edge(int a, int b, bool bidir = true) {
        graph[a].push_back(b);
        if (bidir) {
            graph[b].push_back(a);
        }
    }

    void topoBFS() {
        vector<int> indegree(v, 0);
        for (int i = 0; i < v; i++) {
            for (auto neighbour : graph[i]) {
                indegree[neighbour]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                visited.insert(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            order.push_back(node);
            q.pop();
            for (auto neighbour : graph[node]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        v = numCourses;
        graph.resize(v);

        for (const auto& prereq : prerequisites) {
            add_edge(prereq[1], prereq[0], false);
        }

        topoBFS();

        if (v == visited.size()) return order;
        return {};
    }
};
