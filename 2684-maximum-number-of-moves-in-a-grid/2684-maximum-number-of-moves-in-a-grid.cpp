class Solution {
public:
    int m,n;
    
    int dp[1005][1005];
    
    int f(int i, int j, vector<vector<int>> &grid){
        
        if(j == n - 1)  return 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int ans = 0;
        
        if(i - 1 >= 0 && grid[i - 1][j + 1] > grid[i][j]){
            ans = max(ans,f(i - 1, j + 1,  grid) + 1);
        }
        
        if(grid[i][j + 1] > grid[i][j])     ans = max(ans, f(i, j + 1, grid) + 1);
        
        if(i + 1 < m && grid[i + 1][j + 1] > grid[i][j])    ans = max(ans, f(i + 1, j + 1, grid) + 1);
        
        return dp[i][j] = ans;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        memset(dp,-1,sizeof(dp));
        
        int mx = 0;
        
        for(int i = 0; i<m; i++){
            mx = max(mx, f(i, 0, grid));
        }
        
        return mx;
    }
};