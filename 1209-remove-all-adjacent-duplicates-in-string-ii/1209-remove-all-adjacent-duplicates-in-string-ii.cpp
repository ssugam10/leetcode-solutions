class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<pair<char,int>> st;
        
        
        st.push({s[0],1});
        for(int i = 1; i<n; i++){
            if(!st.empty() && st.top().first == s[i]){
                st.top().second++;
                
                if(st.top().second == k){
                    st.pop();
                }
            }
            else{
                st.push({s[i],1});
            }
        }
        
        string str = "";
        while(!st.empty()){
            for(int i = 0; i<st.top().second ; i++){
                str += st.top().first;
            }
            st.pop();
        }
        
        reverse(str.begin(),str.end());
        return str;
    }
};