#include <stack>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        stack<int> st;  
        
        for(int i = 0; i < n; i++) {
            if(isdigit(s[i])) {
                // If we find a digit, we need to remove the closest non-digit character to the left
                if(!st.empty()) {
                    s[st.top()] = '#';  // Mark the closest non-digit character to the left for removal
                    st.pop();
                }
                s[i] = '#';  // Mark the current digit for removal
            } else {
                st.push(i);  
            }
        }
        
        string result = "";
        for(int i = 0; i < n; i++) {
            if(s[i] != '#') {
                result += s[i];
            }
        }
        
        return result;
    }
};
