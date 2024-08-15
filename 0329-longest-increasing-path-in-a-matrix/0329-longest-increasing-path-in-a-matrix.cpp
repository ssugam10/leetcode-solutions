class Solution {
public:
    int n;
    int m;
    
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    vector<vector<int>> dp;
    
    int f(int i, int j, vector<vector<int>> &grid){
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int maxPath = 1;
        
        for(int k = 0; k<4; k++){
            int new_i = i + dirs[k].first;
            int new_j = j + dirs[k].second;
            
            if(new_i >=0 && new_i < n && new_j >= 0 && new_j < m && grid[i][j] < grid[new_i][new_j]){
                maxPath = max(maxPath, 1 + f(new_i, new_j, grid));
            }
        }
        
        return dp[i][j] = maxPath;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        
        dp.resize(n,vector<int>(m,-1));
        
        int mx = 1;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                mx = max(mx, f(i,j,matrix));
            }
        }
        
        return mx;
        
    }
};