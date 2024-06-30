class Solution {
public:
    int f(vector<int> &nums, int goal, int n){
        if(goal < 0)    return 0;   //since we pass goal - 1 which can become -1 (see constraints)
        int i = 0;
        int j = 0;
        int sum = 0;
        int cnt = 0;
        while(j<n){
            sum += nums[j];
            while(sum > goal){
                sum -= nums[i++];
            }
            cnt += (j-i+1);
            j++;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return f(nums,goal,n) - f(nums,goal-1,n);
    }
};