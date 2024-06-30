class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> psi(n);
        vector<int> nsi(n);

        psi[0] = -1;
        stack<int> st;
        st.push(0);

        for(int i = 0; i<n; i++){
            while(st.size()>0 && heights[st.top()]>=heights[i])   st.pop();

            psi[i] = (st.empty())? -1 : st.top();

            st.push(i);
        }

        nsi[n-1] = n;
        stack<int> s;
        s.push(n-1);
        for(int i = n-2;i>=0;i--){
            while(s.size()>0 && heights[s.top()] >= heights[i])   s.pop();

            nsi[i] = (s.empty())? n : s.top();

            s.push(i);
        }

        int area = -1;
        for(int i = 0; i<n; i++){
            area = max(area,(nsi[i]-psi[i]-1)*heights[i]);
        }

        return area;


    }
};