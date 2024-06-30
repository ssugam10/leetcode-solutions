class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int correctIdx;
        while(i<n){
            if(nums[i]<=0){
                i++;
                continue;
            }
            correctIdx = nums[i]-1;
            if(correctIdx > n-1) i++;
            else if(nums[i]==nums[correctIdx]) i++; //dono case covered, right position and duplicate ele
            else swap(nums[i],nums[correctIdx]);
        }

        for(int i = 0; i<n; i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};