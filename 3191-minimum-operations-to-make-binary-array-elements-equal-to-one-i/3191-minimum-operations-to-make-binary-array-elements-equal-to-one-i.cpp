class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        for(int i = 0; i<n ; i++){
            if(nums[i] == 1)    continue;
            else{
                for(int k = i ; k<i+3; k++){
                    if(k >= n)   return -1;
                    if(nums[k] == 1)    nums[k] = 0;
                    else nums[k] = 1;
                }
                ops++;
            }
        }
        
        return ops;
    }
};