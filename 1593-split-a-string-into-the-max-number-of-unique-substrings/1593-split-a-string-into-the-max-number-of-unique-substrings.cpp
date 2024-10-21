class Solution {
public:
    
    int n;
    int mx;
    
    void f(int i, string &s, unordered_set<string> &st) {
        if (i == n) {
            mx = max(mx, (int)st.size());
            return;
        }
        
        string temp = "";
        for (int j = i; j < n; j++) {
            temp += s[j];
            if (st.find(temp) == st.end()) {
                st.insert(temp);
                f(j + 1, s, st);
                st.erase(temp);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        n = s.length();
        mx = 0;
        unordered_set<string> st;
        f(0, s, st);
        return mx;
    }
};
