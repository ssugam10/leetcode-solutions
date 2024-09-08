#define ll long long int

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ngi(n);
        
        ngi[n - 1] = n - 1;
        st.push(n - 1);
        
        for(int i = n - 2; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            
            if(st.empty())  ngi[i] = n - 1;
            else ngi[i] = st.top();
            
            st.push(i);
        }
        
        int curr = 0;
        ll ans = 0;
        
        while(curr != n - 1){
            ans += (ll)(ngi[curr] - curr) * (ll)nums[curr];    
            curr = ngi[curr];
        }
        
        return ans;
    }
};