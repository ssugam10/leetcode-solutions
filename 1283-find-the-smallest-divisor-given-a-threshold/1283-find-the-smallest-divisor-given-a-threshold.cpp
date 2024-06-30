class Solution {
public:
    bool isPossible(vector<int>& nums, int threshold, int mid, int n){
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += (int)ceil((nums[i]/(double)mid));
        }

        return (sum <= threshold);
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int mex = -1;
        for(int i = 0; i<n; i++){
            mex = max(mex,nums[i]);
        }

        int lo = 1;
        int hi = mex;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isPossible(nums,threshold,mid,n)){
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        return lo;
    }
};