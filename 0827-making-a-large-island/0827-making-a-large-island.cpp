class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int n;  //rows
    int m;  //cols
    
    int mapping(int row, int col){
        return (m * row) + col;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        DisjointSet dsu(n*m);
        
        int largest = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    if(i + 1 < n && grid[i+1][j] == 1){
                        dsu.unionBySize(mapping(i,j), mapping(i+1,j));
                    }
                    
                    if(i - 1 >= 0 && grid[i-1][j] == 1){
                        dsu.unionBySize(mapping(i,j),mapping(i-1,j));
                    }
                    
                    if(j + 1 < m && grid[i][j+1] == 1){
                        dsu.unionBySize(mapping(i,j),mapping(i,j+1));
                    }
                    
                    if(j - 1 >= 0 && grid[i][j-1] == 1){
                        dsu.unionBySize(mapping(i,j),mapping(i,j-1));
                    }
                    
                    largest = max(largest, dsu.size[dsu.findUPar(mapping(i,j))]);
                }
            }
        }
        //Till here we have marked all the connected components in the grid
        
        
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0){
                    int cnt = 0;
                    set<int> parents;
                    
                    if(i + 1 < n && grid[i+1][j] == 1){
                        parents.insert(dsu.findUPar(mapping(i+1,j)));
                    }
                    
                    if(i - 1 >= 0 && grid[i-1][j] == 1){
                        parents.insert(dsu.findUPar(mapping(i-1,j)));
                    }
                    
                    if(j + 1 < m && grid[i][j+1] == 1){
                        parents.insert(dsu.findUPar(mapping(i,j+1)));
                    }
                    
                    if(j - 1 >= 0 && grid[i][j-1] == 1){
                        parents.insert(dsu.findUPar(mapping(i,j-1)));
                    }
                    
                    while(parents.size() > 0){
                        cnt += dsu.size[*(parents.begin())];
                        parents.erase(parents.begin());
                    }
                    
                    largest = max(largest,cnt + 1);
                }
            }
        }
        
        return largest;
    }
};