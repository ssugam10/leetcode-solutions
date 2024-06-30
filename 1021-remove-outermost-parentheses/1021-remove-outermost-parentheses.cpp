class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        stack<char> st;
        string component = "";
        string ans = "";
        for(int i = 0; i<n; i++){
            if(st.empty()){
                st.push(s[i]);  //pushing the initial bracket
            }

            else if(s[i] == '('){
                st.push(s[i]);
                component += '(';
            }

            else if(s[i] == ')' && st.size() == 1){
                st.pop();
                //cout<<component<<"\t"<<i<<endl;
                ans += component;
                component = "";
            }

            else{
                st.pop();
                component += ')';
            }
        }

        return ans;
    }
};