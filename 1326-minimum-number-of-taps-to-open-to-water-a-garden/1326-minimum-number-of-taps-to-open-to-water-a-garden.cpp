class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1,INT_MAX);    //dp[i] tells min number of taps to water 0-ith point

        dp[0] = 0; 
        for(int i = 0; i<=n; i++){
            int start = max(0,i-ranges[i]);
            int end = min(n,i+ranges[i]);

            int ans = INT_MAX;
            for(int j = start ; j<=end; j++){
                ans = min(ans, dp[j]);
            }
            if(ans != INT_MAX){
                dp[end] = min(dp[end],ans+1);   //if ans + 1 < dp[end] then this tap should be turned on for now
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];

    }
};