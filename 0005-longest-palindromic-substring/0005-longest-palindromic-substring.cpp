class Solution {
public:
    string expandAroundCenter(int i, int j,string s, int n){
        while(i >= 0 && j < n && s[i] == s[j]){
            i--;
            j++;
        }
        
        return s.substr(i+1,j - i - 1);
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        
        string ans = s.substr(0,1);
        
        for(int i = 0; i<n; i++){
            string odd = expandAroundCenter(i,i,s,n);
            string even = expandAroundCenter(i,i+1,s,n);
            
            if(odd.size() > ans.size()){
                ans = odd;
            }
            
            if(even.size() > ans.size()){
                ans = even;
            }
        }
        
        return ans;
    }
    
    
};