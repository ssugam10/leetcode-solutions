class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();

        // Remove duplicates by using a set
        set<int> unique_nums(nums.begin(), nums.end());
        nums.assign(unique_nums.begin(), unique_nums.end());

        sort(nums.begin(), nums.end());

        int mx = 1;
        map<int, int> mp;    // maps the number to its greatest square streak
        bool flag = false;

        for(int i = 0; i < nums.size(); i++) {
            int root = sqrt(nums[i]);

            if(mp[nums[i]] == 0) mp[nums[i]] = 1;

            if(root * root == nums[i] && mp[root] > 0) {
                mp[nums[i]] += mp[root];
                flag = true;
            }

            mx = max(mx, mp[nums[i]]);
        }

        if(!flag) return -1;

        return mx;
    }
};
