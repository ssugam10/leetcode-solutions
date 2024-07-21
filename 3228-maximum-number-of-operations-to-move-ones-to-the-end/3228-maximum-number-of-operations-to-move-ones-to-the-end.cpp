class Solution {
public:
    int maxOperations(string s) {
        int ones = 0;
        int cnt = 0;
        int n = s.length();
        
        for(int i = 0; i<n; i++){
            if(s[i] == '1'){
                ones++;
                if(i+1 < n && s[i+1] == '0')    cnt += ones;
            }
        }
        
        return cnt;
    }
};