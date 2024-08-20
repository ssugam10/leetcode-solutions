#define ll long long int

class Solution {
public:
    
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
       int n = A.size();            
        
        vector<vector<ll>> dp(n+1,vector<ll>(2,0));
        
        dp[n - 1][0] = A[n - 1];
        dp[n - 1][1] = B[n - 1];
        
        for(int i = n - 2; i>=0; i--){
            dp[i][0] = A[i] + max(dp[i+1][0], dp[i+2][1]);
            dp[i][1] = B[i] + max(dp[i+1][1], dp[i+2][0]);
        }
        
        return max(dp[0][0], dp[0][1]);
    }
};