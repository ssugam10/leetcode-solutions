class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int correctIdx;
        while(i<n){
            correctIdx = nums[i];
            if(i==correctIdx || correctIdx==n) i++;
            else swap(nums[i],nums[correctIdx]);
        }

        for(int i = 0; i<n; i++){
            if(nums[i] != i) return i;
        }
        return n;
    }
};
