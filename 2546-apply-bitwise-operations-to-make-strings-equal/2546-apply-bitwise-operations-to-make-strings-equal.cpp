class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int n = s.length();
        
        int one = 0;
        
        for(int i = 0; i<n; i++){
            if(s[i] == '1') one++;
        }
        
        for(int i = 0; i < n; i++){
            if(s[i] == '0' && target[i] == '1'){
                if(one < 1) return false;
                one++;
            }
        }
        
        for(int i = 0; i<n; i++){
            if(s[i] == target[i] || s[i] == '0')    continue;
            
            else{
                if(one > 1) one--;
                else return false;
            }
        }
        
        return true;
    }
};