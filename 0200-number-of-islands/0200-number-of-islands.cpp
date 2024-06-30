class Solution {
public:
    vector<vector<int>> visited;
    int n;  //Number of columns
    int m;  //Number of rows

    vector<pair<int,int>> neighbors = {{1,0},{-1,0},{0,1},{0,-1}};

    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(auto neighbor : neighbors){
                int i = row + neighbor.first;
                int j = col + neighbor.second;
                if(!(i < 0 || i>=m || j < 0 || j>=n || grid[i][j]=='0' || visited[i][j] == 1)){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
    } 

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visited.resize(m, vector<int>(n,0));


        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    bfs(grid,i,j);
                }
            }
        }

        return count;
    }
};