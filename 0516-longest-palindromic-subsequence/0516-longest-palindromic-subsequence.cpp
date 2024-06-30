class Solution {
public:
    vector<vector<int>> dp;

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        dp.clear();
        dp.resize(n+1, vector<int>(n+1,0));

        string t = s;
        reverse(t.begin(),t.end());

        cout<<s<<endl;
        cout<<t<<endl;

        // for(int i = 0; i<n; i++){
        //     dp[n][i] = 0;
        //     dp[i][n] = 0;
        // }

        for(int i = n-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(s[i] == t[j]){
                    dp[i][j] = dp[i+1][j+1] + 1;
                }

                else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }

        return dp[0][0];
    }
};