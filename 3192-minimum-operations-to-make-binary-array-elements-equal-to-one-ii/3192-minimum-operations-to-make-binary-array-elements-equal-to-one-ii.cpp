class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        int ops = 0;
        
        for(int i = n - 1; i >= 1; i--){
            if(nums[i] != nums[i - 1]) ops++;
        }
        
        ops += (nums[0] == 0);
        
        return ops;
    }
};