class Solution {
public:
    int ans(vector<int>& nums, int a, int b) {
        int c = 0;
        int k = -1; // Use -1 to indicate an initial state where no number is chosen
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == a || nums[i] == b) {
                if (nums[i] != k) {
                    c++;
                }
                k = nums[i];
            }
        }
        return c;
    }

    int maximumLength(vector<int>& nums1, int k) {
        vector<int> v(k, 0); // Initialize the vector to count occurrences of remainders
        
        vector<int>nums;
        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = nums1[i] % k;
            v[nums1[i]]++;
            
            if(nums.size()==0){
                nums.push_back(nums1[i]);
            }
            else{ 
            if(nums1[i]!=nums.back())
                nums.push_back(nums1[i]);
            }
        }
        
        int mx = *max_element(v.begin(), v.end());
        
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if(v[i]>0 && v[j]>0)
                mx = max(mx, ans(nums, i, j));
            }
        }
        return mx;
    }
};