class Solution {
public:
    int n;
    vector<int> dp;
    
    int f(int i, vector<int> &nums){
        if(i == n - 1)  return 0;
        if(nums[i] == 0)    return INT_MAX;
        
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int k = 1; k <= nums[i]; k++){
            if(i + k >= n)  break;
            ans = min(ans, f(i+k,nums));
        }
        
        if(ans == INT_MAX)  return INT_MAX;
        
        return dp[i] = ans + 1;
    }
    
    int jump(vector<int>& nums) {
        n = nums.size();
        dp.clear();
        dp.resize(n+1,-1);
        
        return f(0,nums);
    }
};