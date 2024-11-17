class Solution {
public:
    bool isValid(vector<int> &nums, vector<vector<int>>& queries, int mid) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < mid; i++) {
            diff[queries[i][0]] -= queries[i][2];
            if (queries[i][1] + 1 < n) {
                diff[queries[i][1] + 1] += queries[i][2];
            }
        }
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] + diff[i] > 0) return false;
        }
        return true;
    }
    
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int lo = 0, hi = queries.size(), result = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (isValid(nums, queries, mid)) {
                result = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return result == -1 ? -1 : result;
    }
};
