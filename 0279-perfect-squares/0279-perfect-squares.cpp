class Solution {
public:
    int dp[10005];
    
    int f(int n){
        if(n == 0)  return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int ans = n;
        
        for(int i = 1; i * i <= n; i++){
            ans = min(ans, f(n - i * i));    
        }        
        
        ans++;
        
        return dp[n] = ans;
    }
    
    int numSquares(int n) {
        
        memset(dp,-1,sizeof(dp));
        
        return f(n);
    }
};