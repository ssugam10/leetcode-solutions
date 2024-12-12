#define ll long long int

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<ll> pre(1,0);
        
        int n = nums.size();
        
        ll ans = LLONG_MIN;
        
        for(int ele : nums) pre.push_back(pre.back() + ele);
        
        for(int kadanes = 0; kadanes < k; kadanes++){
            ll sum = 0;
            for(int i = kadanes; i + k <= n; i += k){
                ll num = pre[i + k] - pre[i];
                
                sum = max(num, sum + num);
                ans =  max(ans, sum);
            }
        }
        
        return ans;
    }
};