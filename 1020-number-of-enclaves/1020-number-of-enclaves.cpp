class Solution {
public:
    vector<vector<bool>> visited;
    int m;  //rows  
    int n;  //cols

    int boundaryOnes = 0;

    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<int>>& grid){
        visited[i][j] = true;
        boundaryOnes++;

        for(int k = 0; k<4; k++){
            int ro = i + dir[k].first;
            int co = j + dir[k].second;


            if(ro < 0 || ro >= m || co < 0 || co >= n || visited[ro][co] || !grid[ro][co])  continue;

            dfs(ro,co,grid);
        }

    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visited.clear();
        visited.resize(m,vector<bool>(n,false));

        int tot_one = 0;

        for(int i = 0; i<m ; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]){
                    tot_one++;
                    if(!visited[i][j] && (i == 0 || i == m-1 || j == 0 || j == n-1))  dfs(i,j,grid);
                }
            }
        }

        return tot_one - boundaryOnes;

    }
};