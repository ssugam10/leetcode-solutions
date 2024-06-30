class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        ans[n-1] = 0;
        stack<int> st;
        st.push(heights[n-1]);

        for(int i = n-2; i>=0; i--){
            int count = 0;
            while(st.size()>0 && st.top()<=heights[i]){
                count++;
                st.pop();
            }
            if(!st.empty()) count++;

            ans[i] = count;

            st.push(heights[i]);
        }

        return ans;
    }
};