class Solution {
public:
    int minAddToMakeValid(string s) {
        int closed = 0;
        
        int n = s.length();
        stack<char> st;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push('(');
            }
            else{
                if(st.size() > 0)   st.pop();
                else{
                    closed++;
                }
            }
        }
        
        return st.size() + closed;
    }
};