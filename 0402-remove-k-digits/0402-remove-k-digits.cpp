class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && num[i] < st.top()) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while (k > 0) {
            st.pop();
            k--;
        }
        
        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        // Remove leading zeros
        int non_zero_index = 0;
        while (non_zero_index < res.size() && res[non_zero_index] == '0') {
            non_zero_index++;
        }
        
        res = res.substr(non_zero_index);
        
        if (res.empty()) {
            return "0";
        }
        
        return res;
    }
};
