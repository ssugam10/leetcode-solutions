class Solution {
public:
    vector<int> lenKSub(vector<int>& nums, int k) {
        if (k == 0) return {};
        if (k >= nums.size()) return nums;
        
        vector<int> st;
        int n = nums.size();
        int toRemove = n - k;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && toRemove > 0 && st.back() < nums[i]) {
                st.pop_back();
                toRemove--;
            }
            st.push_back(nums[i]);
        }
        
        return vector<int>(st.begin(), st.begin() + k);
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i = 0, j = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                result.push_back(nums1[i++]);
            } else if (nums1[i] < nums2[j]) {
                result.push_back(nums2[j++]);
            } else {
                // Compare suffixes to break ties
                if (vector<int>(nums1.begin() + i, nums1.end()) > vector<int>(nums2.begin() + j, nums2.end())) {
                    result.push_back(nums1[i++]);
                } else {
                    result.push_back(nums2[j++]);
                }
            }
        }
        
        while (i < nums1.size()) result.push_back(nums1[i++]);
        while (j < nums2.size()) result.push_back(nums2[j++]);
        
        return result;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<int> ans;
        for (int i = 0; i <= k; i++) {
            int j = k - i;
            
            if (i <= n && j <= m) {
                vector<int> v1 = lenKSub(nums1, i);
                vector<int> v2 = lenKSub(nums2, j);
                vector<int> candidate = merge(v1, v2);
                
                if (candidate > ans) {
                    ans = candidate;
                }
            }
        }
        
        return ans;
    }
};
