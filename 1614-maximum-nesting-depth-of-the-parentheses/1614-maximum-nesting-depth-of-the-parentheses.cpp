class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        
        long long int mx = 0;
        
        stack<int> st;
        
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
                mx = max(mx,(long long int)st.size());
            }
            else if(s[i] == ')'){
                st.pop();
            }
        }
        
        return mx;
    }
};