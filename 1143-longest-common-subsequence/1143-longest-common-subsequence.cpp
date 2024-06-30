class Solution {
public:

    vector<vector<int>> dp;

    int longestCommonSubsequence(string s1, string s2) {
        dp.clear();
        dp.resize(1005, vector<int> (1005,0));

        for(int i = s1.size()-1; i>=0; i--){
            for(int j = s2.size()-1; j>=0; j--){
                int ans = 0;
                if(s1[i] == s2[j]){
                    ans = 1 + dp[i+1][j+1];
                }
                else{
                    ans = max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
        

    }
};