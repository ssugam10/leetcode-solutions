class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int original = nums.size();
        
        // Extend the array to simulate circular array
        for (int i = 0; i < original - 1; i++) {
            nums.push_back(nums[i]);
        }
        
        int n = nums.size();
        stack<int> st;
        
        vector<int> nge(n, 0); // Vector to store next greater elements
        nge[n - 1] = -1; // Last element in circular array has no greater element by default
        
        st.push(nums[n - 1]);
        
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && nums[i] >= st.top()) {
                st.pop();
            }
            
            if (!st.empty()) {
                nge[i] = st.top();
            } else {
                nge[i] = -1;
            }
            
            st.push(nums[i]);
        }
        
        // Prepare the result vector containing only the next greater elements for the original array
        vector<int> ans(original);
        for (int i = 0; i < original; i++) {
            ans[i] = nge[i];
        }
        
        return ans;
    }
};
