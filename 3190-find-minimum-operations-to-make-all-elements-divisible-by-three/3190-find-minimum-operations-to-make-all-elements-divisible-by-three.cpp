class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for(int i = 0; i<nums.size(); i++){
            int rem = nums[i] % 3;
            int ans = min(rem,3-rem);
            ops += ans;
        }
        return ops;
    }
};