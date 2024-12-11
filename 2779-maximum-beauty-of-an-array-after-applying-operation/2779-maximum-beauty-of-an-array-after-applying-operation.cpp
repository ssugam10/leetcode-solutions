class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> overlap(200005, 0);
        
        for(int i = 0; i<n; i++){
            overlap[max(nums[i] - k, 0)]++;
            overlap[nums[i] + k + 1]--;
        }
        
        for(int i = 1; i <= 1e5; i++)   overlap[i] += overlap[i - 1];
        
        return *max_element(overlap.begin(),overlap.end());
    }
};