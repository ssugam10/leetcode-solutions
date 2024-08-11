class Solution {
public:
    int dfs(int node, int par, vector<list<int>> &adj, int &good){
        set<int> childrenSize;
        int currSize = 0;
        for(auto adjNode : adj[node]){
            if(adjNode == par)  continue;
            
            int size = dfs(adjNode, node, adj, good);
            
            currSize += size;
            childrenSize.insert(size);
        }
        
        if(childrenSize.size() <= 1){
            good++;
        }
        
        return currSize + 1;
    }
    
    int countGoodNodes(vector<vector<int>>& edges) {
        vector<list<int>> adj(1e5);
        
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        //0 is the root
        
        int good = 0;
        dfs(0,-1,adj,good);
        
        
        return good;
    }
};