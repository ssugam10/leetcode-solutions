class Solution {
public:
    int f(int node, int parent, vector<vector<int>> &graph, int &dia) {
        int maxDepth = 0; // single node contributes depth 0
        
        for (auto child : graph[node]) {
            if (child == parent) continue;

            int depth = f(child, node, graph, dia);
            
            dia = max(dia, maxDepth + depth + 1); // Update diameter with current depth sum
            maxDepth = max(maxDepth, depth + 1); // Update maxDepth
        }

        return maxDepth;
    }
    
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1; // Nodes in graph1
        int m = edges2.size() + 1; // Nodes in graph2
        
        vector<vector<int>> graph1(n), graph2(m);
        
        for (auto edge : edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        
        for (auto edge : edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }
        
        int dia1 = 0, dia2 = 0;
        f(0, -1, graph1, dia1); // Compute diameter of graph1
        f(0, -1, graph2, dia2); // Compute diameter of graph2
        
        //cout<<dia1<<" "<<dia2<<endl;
        
        // Combine the diameters with the merging point contributing +1
        return max({dia1, dia2, (dia1 + 1) / 2 + (dia2 + 1) / 2 + 1});
    }
};
