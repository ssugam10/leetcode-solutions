#define ll long long int
class Solution
{
public:
    bool checkVowel(unordered_map<char,ll> &mp){
        for (auto ele : mp)
        {
            if (ele.second == 0)
            {
                return false;
            }
        }
        
        return true;
    }
    
    
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    
    long long countOfSubstrings(string word, int k)
    {
        int n = word.size();
        
        vector<int> nextConsonant(n,0);
        int lastConsonant = n;
        for (int i = n - 1; i >= 0; i--) {
            nextConsonant[i] = lastConsonant;
            if (!isVowel(word[i])) lastConsonant = i;
        }
        

        ll conso = 0;
        ll cnt = 0;

        unordered_map<char, ll> mp;
        mp['a'] = 0;
        mp['e'] = 0;
        mp['i'] = 0;
        mp['o'] = 0;
        mp['u'] = 0;

        int i = 0;
        int j = 0;
        
        bool flag = true;

        while (j < n && i < n)
        {
            if(flag){
                
                if(isVowel(word[j])){
                    mp[word[j]]++;
                }
                
                else    conso++;
            }
            else{
                if(conso < k || !checkVowel(mp)){
                    flag = true;
                    j++;
                    continue;
                }
            }
            
            
            if(conso == k){
                if(checkVowel(mp)){
                    cnt += (nextConsonant[j] - j);
                    
                    if(isVowel(word[i]))    mp[word[i]]--;
                    else conso--;
                    
                    i++;
                    flag = false;
                }
                
                else j++;
            }
            else if(conso > k){
                while(i < n && isVowel(word[i])){
                    mp[word[i]]--;
                    i++;
                }
                
                conso--;
                i++;
                j++;
            }
            else{
                j++;
            }
        }

       
        return cnt;
    }
};