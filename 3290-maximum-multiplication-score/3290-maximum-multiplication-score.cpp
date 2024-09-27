#define ll long long int

class Solution {
public:
    int n;
    
    ll dp[4][100005];
    
    ll f(int i, int j, vector<int>&a, vector<int> &b) {
        if(i == 4) return 0;
        if(j == n) return LLONG_MIN;
        
        if(dp[i][j] != LLONG_MAX) return dp[i][j];
        
        ll result = LLONG_MIN;
        
        // Option 1: Pick b[j] and move to the next index for both 'a' and 'b'
        ll ans = f(i+1, j+1, a, b); 
        if(ans != LLONG_MIN) result = 1LL * a[i] * b[j] + ans;
        
        // Option 2: Skip b[j] and move to the next index in 'b'
        result = max(result, f(i, j+1, a, b));
        
        return dp[i][j] = result;
    }
    
    long long maxScore(vector<int>& a, vector<int>& b) {
        n = b.size();
        
        // Initialize dp array with LLONG_MAX using a loop
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < n; ++j) {
                dp[i][j] = LLONG_MAX;
            }
        }
        
        return f(0, 0, a, b);
    }
};
