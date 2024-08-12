#define ll long long int

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int mod = 1e9 + 7;
        
        ll ans = (((1LL * nums[0] * nums[0]) % mod) * nums[0]) % mod;
        
        ll prev = nums[0];
        
        for(int i = 1; i<nums.size(); i++){
            prev = (2 * prev) % mod + nums[i] - nums[i - 1];
            ans =  (ans % mod + ((1LL * nums[i] * nums[i]) % mod * (prev % mod)) % mod) % mod ;
        }
        
        return ans;
    }
};