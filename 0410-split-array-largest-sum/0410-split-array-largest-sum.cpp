class Solution {
public:
    int partitions(vector<int> &nums, int mid, int n){
        int cnt = 1;
        int sum = 0;
        for(int i = 0; i<n; i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                sum = nums[i];
                cnt++;
            }
        }
        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int lo = -1;
        int hi = 0;
        for(int i = 0; i<n; i++){
            lo = max(lo,nums[i]);
            hi += nums[i];
        }

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int divisions = partitions(nums,mid,n);
            if(divisions > k){
                lo = mid + 1;
            }
            else    hi = mid - 1;
        }

        return lo;
    }
};