class Solution {
public:
    int find(int x, vector<int> &parent){
        if(x == parent[x])  return x;
        return parent[x] = find(parent[x],parent);
    }
    
    bool unionByRank(int childa, int childb, vector<int> &parent, vector<int> &rank){
        int a = find(childa,parent);
        int b = find(childb,parent);
        
        if(a == b)  return true;
        
        if(rank[a] > rank[b]){
            parent[b] = a;
            rank[a]++;
        }
        else if(rank[b] > rank[a]){
            parent[a] = b;
            rank[b]++;
        }
        else{
            rank[a]++;
            parent[b] = a;
        }
        
        return false;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
        
        vector<int> rank(n,1);
        
        int extraCables = 0;
        for(int i = 0; i<connections.size(); i++){
            bool isConnected = unionByRank(connections[i][0],connections[i][1], parent, rank);
            if(isConnected){
                extraCables++;
            }
        }
        
        set<int> cc;
        for(int i = 0; i<parent.size(); i++){
            int par = find(parent[i],parent);
            cc.insert(par);
        }
        
        if(cc.size() <= extraCables + 1)    return cc.size() - 1;
        return -1;
    }
};