class Solution {
public:
    vector<vector<bool>> dp;

    bool canPartition(vector<int>& arr) {
        int s = 0;
        for(int i = 0; i<arr.size(); i++)  s+= arr[i];

        if(s % 2 != 0)  return false;

        dp.clear();
        dp.resize(205,vector<bool>(10000,false));

        int k = s/2;
        int n = arr.size();

        dp[n][0] = true;

        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<=k; j++){
                if(arr[i] <= j){
                    dp[i][j] = dp[i+1][j-arr[i]] || dp[i+1][j];
                }
                else{
                    dp[i][j] = dp[i+1][j];
                }
                
            }
        }


        return dp[0][k];
    }
};