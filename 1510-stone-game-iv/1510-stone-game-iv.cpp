class Solution {
public:
    bool winnerSquareGame(int n) {
       
        vector<bool> dp(n+1);
        dp[0] = false;
        dp[1] = true;
        
        for(int i = 2; i<=n; i++){
            bool ans = false;
            for(int j = 1; j*j <= i; j++){
                if(!dp[i - j*j]){
                    ans = true;
                    break;
                }
            }
            
            dp[i] = ans;
        }
        
        
        return dp[n];
    }
};