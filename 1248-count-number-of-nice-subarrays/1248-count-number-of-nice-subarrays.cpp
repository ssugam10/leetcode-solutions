class Solution {
public:
    int f(vector<int> &nums, int k, int n){
        int i = 0;
        int j = 0;
        int odd_nums = 0;
        int cnt = 0;
        while(j<n){
            if(nums[j] & 1){
                odd_nums++;
            }

            while(odd_nums > k){
                if(nums[i] & 1){
                    odd_nums--;
                }
                i++;
            }

            cnt += (j-i+1);
            j++;
        }

        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        return f(nums,k,n) - f(nums,k-1,n);
    }
};