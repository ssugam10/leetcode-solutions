class Solution {
public:
    vector<vector<int>> constructGridLayout(int N, vector<vector<int>>& edges) {
        vector<vector<int>> adj(N);
        
        // Build the adjacency list
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Degree list of each node
        vector<int> deg(N);
        for (int i = 0; i < N; ++i) {
            deg[i] = adj[i].size();
        }
        
        // Finding the root node with the minimum degree
        int root = min_element(deg.begin(), deg.end()) - deg.begin();
        
        // Initial path starting from the root node
        vector<int> path = {root};
        vector<int> seen(N, 0);
        seen[root] = 1;

        // Build the path by expanding from the root
        for (int i = 0; i < path.size(); ++i) {
            int node = path[i];
            if (path.size() >= 2 && deg[path.back()] == deg[root]) break;

            // Sort neighbors by degree
            sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
                return deg[a] < deg[b];
            });

            // Add the next valid neighbor to the path
            for (int nei : adj[node]) {
                if (!seen[nei] && deg[nei] <= deg[root] + 1) {
                    path.push_back(nei);
                    seen[nei] = 1;
                    break;
                }
            }
        }

        // Now we have the first row as the path
        int C = path.size();
        int R = (N + C - 1) / C; // Round up to determine the number of rows
        
        // Prepare the grid
        vector<vector<int>> ans(R, vector<int>(C, -1));
        ans[0] = path;
        
        // Fill the remaining rows
        for (int r = 1; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                for (int nei : adj[ans[r - 1][c]]) {
                    if (!seen[nei]) {
                        ans[r][c] = nei;
                        seen[nei] = 1;
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};
