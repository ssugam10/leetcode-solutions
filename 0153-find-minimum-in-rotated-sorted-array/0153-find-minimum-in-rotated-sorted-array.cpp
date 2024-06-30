class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;

        if(nums[hi] >= nums[lo]) return nums[lo];

        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(mid > 0 && nums[mid] < nums[mid-1]){
                return nums[mid];
            }
            else if(mid < n-1 && nums[mid] > nums[mid+1]){
                return nums[mid+1];
            }
            else if(nums[mid] > nums[hi]){
                lo = mid + 1;
            }
            else if(nums[mid] < nums[hi]){
                hi = mid - 1;
            }
        }

        return -1;
    }
};