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
        
        while(j < n){
            temp[word1[j]]++;
            
            bool flag = true;
            
            while(flag){
                for(auto ele : freq){
                    if(ele.second > temp[ele.first]){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    cnt += (n - j);
                    temp[word1[i]]--;
                    i++;
                }
            }
            
            j++;
        }
        
        bool flag = true;    
        while(flag){
            for(auto ele : freq){
                if(ele.second > temp[ele.first]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                cnt += (n - j);
                temp[word1[i]]--;
                i++;
            }
        }
        
        return cnt;
        
    }
};