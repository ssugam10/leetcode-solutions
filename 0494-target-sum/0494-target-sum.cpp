class Solution {
public:
    vector<vector<int>> dp;


    int findWays(vector<int>& nums, int target, int i){

        if(i == nums.size() && target == 0){
            return 1;
        }

        if(i == nums.size())    return 0;

        if(dp[i][target+2000] != -1)    return dp[i][target+2000];

        int ans = 0;
        //add
        ans = findWays(nums,target-nums[i],i+1);

        //subtract
        ans += findWays(nums, target+nums[i],i+1);

        return dp[i][target+2000] = ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        dp.resize(nums.size(), vector<int>(5000,-1));
        return findWays(nums,target,0);
    }
};