#define ll long long int

class Solution {
public:
    int n;
    vector<ll> dp;

    ll f(int i, vector<int> &nums) {
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];

        ll ans = 0;

        ans = nums[i] + f(i+1,nums);        

        if(i+1 < n){
            ans = max(ans, nums[i] - nums[i+1] + f(i+2,nums));
        }

        return dp[i] = ans;
    }
    
    ll fbu(vector<int> &nums){
        dp[n] = 0;
        dp[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            dp[i] = max(nums[i] + dp[i+1], nums[i] - nums[i+1] + dp[i+2]);
        }
        return dp[0];
    }

    long long maximumTotalCost(vector<int>& nums) {
        n = nums.size();
        dp.resize(n+1,0);
        return fbu(nums);
    }
};
