class Solution {
public:
    vector<vector<int>> dp;

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        dp.clear();
        dp.resize(n, vector<int>(n,-1));

        for(int i = 0; i<n; i++){
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int i = n-2; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                dp[i][j] = dp[i+1][j];

                if(j + 1 < n){
                    dp[i][j] = min(dp[i][j], dp[i+1][j+1]);
                }

                if(j - 1 >= 0){
                    dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
                }

                dp[i][j] += matrix[i][j];
            }
        }

        int mini = INT_MAX;
        for(int i = 0; i<n; i++){
            mini = min(mini, dp[0][i]);
        }

        return mini;
    }
};