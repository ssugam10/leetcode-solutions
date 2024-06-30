#define ll long long int

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i<n; i++){
            pre[i] = pre[i-1] + nums[i];
            if(pre[i] % k == 0) return true;
        }

        unordered_map<ll,ll> rem;
        for(int i = 0; i<n; i++){
            int remainder = pre[i]%k;
            if(rem.find(remainder) != rem.end()){
                if(i - rem[remainder] >= 2){
                    return true;
                }
            }
            else{
                rem[remainder] = i;
            }
        }

        return false;
    }
};