class Solution {
public:
    int n;
    
    int dp[105][105][105];

    int f(int i, int one, int two, vector<int> &nums, int &k) {
        if (i == n) return 0;
        
        if(dp[i][one][two] != -1)   return dp[i][one][two];

        int mx = INT_MAX;

        // Only apply operation 1
        if (one > 0) {
            int afterOp = ceil((nums[i] * 1.0) / 2);
            int result = f(i + 1, one - 1, two, nums, k);
            if (result != INT_MAX) {
                mx = min(mx, result + afterOp);
            }
        }

        // Only apply operation 2
        if (two > 0 && nums[i] >= k) {
            int result = f(i + 1, one, two - 1, nums, k);
            if (result != INT_MAX) {
                mx = min(mx, result + (nums[i] - k));
            }
        }

        // Operation 1 then 2
        if (one > 0 && two > 0 && nums[i] >= 2 * k - 1) {
            int afterOne = ceil(nums[i] / 2.0);
            int result = f(i + 1, one - 1, two - 1, nums, k);
            if (result != INT_MAX) {
                mx = min(mx, result + (afterOne - k));
            }
        }

        // Operation 2 then 1
        if (one > 0 && two > 0 && nums[i] >= k) {
            int afterTwo = nums[i] - k;
            int afterOne = ceil(afterTwo / 2.0);
            int result = f(i + 1, one - 1, two - 1, nums, k);
            if (result != INT_MAX) {
                mx = min(mx, result + afterOne);
            }
        }
        
        //Just skip
        int result = f(i + 1, one, two, nums, k);
        if(result != INT_MAX){
            mx = min(mx, result + nums[i]);
        }

        return dp[i][one][two] = mx;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        n = nums.size();
        
        memset(dp,-1,sizeof(dp));
        
        return f(0, op1, op2, nums, k);
    }
};
