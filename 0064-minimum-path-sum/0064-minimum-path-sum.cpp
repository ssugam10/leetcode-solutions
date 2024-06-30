class Solution {
public:
    vector<vector<int>> dp;
    int fbu(vector<vector<int>>& ans){
        dp.clear();
        dp.resize(205,vector<int>(205,INT_MAX));

        int n = ans.size();
        int m = ans[0].size();

        // dp[n-1][m-1] = ans[n-1][m-1];
        dp[n-1][m-1] = 0;

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(i+1 < n){
                    dp[i][j] = min(dp[i][j],dp[i+1][j]);
                }
                if(j+1 < m){
                    dp[i][j] = min(dp[i][j], dp[i][j+1]);
                }
                dp[i][j] += ans[i][j];
            }
        }

        return dp[0][0];
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        return fbu(grid);
    }
};