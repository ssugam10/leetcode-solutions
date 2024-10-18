class Solution {
public:
    int n;
    vector<vector<int>> dp; // Memoization table
    
    int countSubsets(int index, int currentMask, vector<int> &nums) {
        // Base case: If we have considered all elements and the current mask is zero
        if (index == n && currentMask == 0) return 1;
        
        // If we considered all elements but mask is non-zero
        if (index == n) return 0;

        // Check if this state has already been computed
        if (dp[index][currentMask] != -1) {
            return dp[index][currentMask];
        }

        int count = 0;
        int newMask = currentMask;

        // Try including nums[index] in the subset
        for (int bit = 0; bit < 32; ++bit) {
            if ((nums[index] & (1 << bit)) && (currentMask & (1 << bit))) {
                newMask ^= (1 << bit); // Toggle bits of the mask that are in nums[index]
            }
        }
        // Recur with nums[index] included
        count = countSubsets(index + 1, newMask, nums);

        // Recur without including nums[index]
        count += countSubsets(index + 1, currentMask, nums);

        // Store the result in dp array before returning
        return dp[index][currentMask] = count;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        int maxOrValue = 0;

        // Compute the OR of all elements in nums
        for (int i = 0; i < n; ++i) {
            maxOrValue |= nums[i];
        }

        // Initialize dp array with -1 indicating uncomputed states
        dp.assign(n, vector<int>(maxOrValue + 1, -1));

        // Start the recursion with all bits set in maxOrValue
        return countSubsets(0, maxOrValue, nums);
    }
};
