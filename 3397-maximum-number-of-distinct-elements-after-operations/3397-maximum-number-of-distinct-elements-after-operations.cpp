class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int prev = INT_MIN, dups = 0;
        for (int n : nums)
            if (prev >= n + k)
                ++dups;
            else
                prev = max(prev + 1, n - k);
        return nums.size() - dups;
    }
};