class Solution {
public:    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<long long>s(nums.begin(), nums.begin() + k);
        vector<double>v;
        auto mid = next(s.begin(), k / 2);
        int n=nums.size();
        for (int i = k;;i++) {
            if (k % 2 == 0) {
                v.push_back((*mid + *prev(mid, 1)) / 2.0);
            } else {
                v.push_back(*mid);
            }

            if(i==n)
            break;
        
            s.insert(nums[i]);
            if (nums[i] < *mid) mid--;

            if (nums[i - k] <= *mid) mid++;
            s.erase(s.lower_bound(nums[i - k]));
        }
        
        return v;
}
};