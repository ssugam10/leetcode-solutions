class Solution {
public:
    bool solve(bool hasTrue, bool hasFalse, char op){
        if(op == '|'){
            if(hasTrue) return true;
            else return false;
        }
        else if(op == '&'){
            if(hasFalse)    return false;
            return true;
        }
        else{
            if(hasTrue) return false;
            return true;
        }
    }
    
    bool parseBoolExpr(string expression) {
        stack<char> st;
        int n = expression.length();
        
        for(int i = 0; i<n; i++){
            char ch = expression[i];
            if(ch == ',')    continue;
            
            if(ch != ')'){
                st.push(ch);   
            }
            else{
                bool hasTrue = false;
                bool hasFalse = false;
                while(st.top() != '('){
                    if(st.top() == 't') hasTrue = true;
                    if(st.top()  == 'f')  hasFalse = true;
                    st.pop();
                }
                st.pop();   //pop the opening parentheses
                char op = st.top();
                st.pop();   //pop the boolean operator
                bool ans = solve(hasTrue,hasFalse,op);
                if(ans) st.push('t');
                else st.push('f');
            }
            
        }
        
        return (st.top() == 't');
    }
};