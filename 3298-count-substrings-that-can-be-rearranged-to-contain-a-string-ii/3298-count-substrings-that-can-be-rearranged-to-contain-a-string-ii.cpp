#define ll long long int

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        unordered_map<char,ll> freq, temp;
        for(auto ele : word2){
            freq[ele]++;
        }
        
        
        int i = 0;
        int j = 0;
        
        ll cnt = 0;
        ll mismatch = word2.size();
        
        while(j < n){
            if(temp[word1[j]] < freq[word1[j]])  mismatch--;
            temp[word1[j]]++;
            
            while(mismatch == 0){
                cnt += (n - j);
                temp[word1[i]]--;
                if(temp[word1[i]] < freq[word1[i]]) mismatch++;
                i++;
            }
            
            j++;
        }
        
        while(mismatch == 0){
            cnt += (n - j);
            temp[word1[i]]--;
            if(temp[word1[i]] < freq[word1[i]]) mismatch++;
            i++;
        }
        
        return cnt;
        
    }
};