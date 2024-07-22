class Solution {
public:
    int find(int node, vector<int> &parent){
        if(node == parent[node]){
            return node;
        }
        
        return parent[node] = find(parent[node],parent);
    }
    
    bool unionByRank(int a, int b, vector<int> &parent, vector<int> &rank){
        int parentA = find(a,parent);
        int parentB = find(b,parent);
        
        if(parentA == parentB){
            return false;
        }
        
        if(rank[parentA] > rank[parentB]){
            parent[parentB] = parentA;
        }
        else if(rank[parentB] > rank[parentA]){
            parent[parentA] = parentB;
        }
        else{
            parent[parentB] = a;
            rank[parentA]++;
        }
        
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<int> parent(n+1,0);
        vector<int> rank(n+1,1);
        
        for(int i = 1; i<=n; i++){
            parent[i] = i;
        }
        
        for(int i = 0; i<n; i++){
            bool isPossible = unionByRank(edges[i][0], edges[i][1], parent, rank);
            if(!isPossible){
                return {edges[i][0], edges[i][1]};
            }
        }
        
        return {};
    }
};