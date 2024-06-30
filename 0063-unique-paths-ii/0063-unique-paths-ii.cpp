#define ll long long

class Solution {
public:
    vector<vector<ll>> dp;
    int fbu(vector<vector<int>>& grid){
        dp.clear();
        dp.resize(105,vector<ll>(105,0));

        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;

        dp[n-1][m-1] = 1;

        for(int i = n-1; i>=0 ; i--){
            for(int j = m-1; j>=0; j--){
                if(i+1<n && grid[i+1][j] == 0){
                    dp[i][j] += dp[i+1][j];
                }

                if(j+1 < m && grid[i][j+1] == 0){
                    dp[i][j] += dp[i][j+1];
                }
            }
        }

        return dp[0][0];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return fbu(obstacleGrid);
    }
};