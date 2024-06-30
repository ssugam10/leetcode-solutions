class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_set<int> st;
        int ct = 0;

        int i = 0;
        int j = 0;

        while(j<n){
            int ch = (int)s[j];
            if(st.find(ch) != st.end()){
                ct = max(ct,j-i);
                while(s[i] != s[j]){
                    st.erase((int)s[i]);
                    i++;
                }
                i++;
            }
            else{
                st.insert(ch);
            }

            j++;
        }

        ct = max(ct,j-i);

        return ct;
    }
};