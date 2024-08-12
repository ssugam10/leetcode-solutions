class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        const int mod = 1e9 + 7;
        
        int dp[2005][55];   //dp[i][j] represents number of monotonic pairs of length i whose arr1[i - 1] = j
        
        memset(dp,0,sizeof(dp));
        
        int n = nums.size();
        
        for(int j = 0; j<=nums[0]; j++){
            int j2 = nums[0] - j;
            dp[1][j] = 1;
        }
        
        for(int i = 2; i<=n; i++){
            for(int j = 0; j <= nums[i - 1]; j++){
                int j2 = nums[i - 1] - j;   //j2 is fixed if j(arr1) is fixed
                
                for(int k = 0; k <= min(nums[i - 2], j); k++){
                    int k2 = nums[i - 2] - k;   //k(arr1) and k2 are the prev elements of both arrays respectively
                    
                    if(k2 < j2) break;
                    
                    dp[i][j] += (dp[i - 1][k] % mod);
                    dp[i][j] %= mod;
                }
            }
        }
        
        
        int ans = 0;
        for(int i = 0; i<=nums[n - 1]; i++){
            ans = (ans % mod + dp[n][i] % mod) % mod;
        }
        return ans;
        
    }
};