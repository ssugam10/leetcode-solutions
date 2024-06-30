class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i = 0;
        int j = 0;

        unordered_map<char,int> mp;
        int maxLen = 0;

        while(j < n){
            mp[s[j]]++;
            int maxFreq = 0;
            for(auto ele : mp){
                maxFreq = max(maxFreq,ele.second);
            }

            while(j-i+1-maxFreq > k){
                mp[s[i]]--;
                maxFreq = 0;
                for(auto ele : mp){
                    maxFreq = max(maxFreq,ele.second);
                }
                i++;
            }
        
            //valid
            maxLen = max(maxLen,j-i+1);
            j++;
        
        }

        return maxLen;
    }
};