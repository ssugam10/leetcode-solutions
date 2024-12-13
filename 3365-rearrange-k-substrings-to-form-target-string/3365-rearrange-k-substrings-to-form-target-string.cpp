class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        
        int n = s.length();
        
        int len = n / k;
        
        map<string, int> mp;
        
        for(int i = 0; i < n; i += len){
            mp[s.substr(i,len)]++;
        }
    
        for(int i = 0; i < n; i += len){
            string temp = t.substr(i,len);
            if(mp[temp] == 0)   return false;
            
            mp[temp]--;
        }
        
        return true;
    }
};