class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        
        vector<int> freq(3,0);
        
        int cnt = 0;
        
        while(j < n){
            freq[s[j] - 'a']++;
            
            bool flag = true;
            for(int i = 0; i<3; i++){
                if(freq[i] == 0)    flag = false;
            }
            
            while(flag){
                cnt += (n - j);
                freq[s[i] - 'a']--;
                i++;
                
                for(int i = 0; i<3; i++){
                    if(freq[i] == 0)    flag = false;
                }
            }
                
            j++;
        }
        
        return cnt;
    }
};