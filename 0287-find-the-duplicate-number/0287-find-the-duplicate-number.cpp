class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int correctIdx;
        do{
            correctIdx = nums[0];
            swap(nums[0],nums[correctIdx]);
        }while(nums[0] != nums[correctIdx]);
        return nums[0];
    }
};