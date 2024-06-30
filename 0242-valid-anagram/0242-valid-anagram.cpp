class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        if(n!=t.length())  return false;

        
        unordered_map<char,int> mp;

        for(int i = 0; i<n; i++){
            mp[s[i]]++;
        }

        for(int i = 0 ; i<n; i++){
            if(mp[t[i]] > 1){
                mp[t[i]]--;
            }
            else if(mp[t[i]] == 1)  mp.erase(t[i]);
            else return false;  //mp[<something that does not exist>]   returns 0 which is covered in this case
        }

        if(mp.empty())  return true;
        return false;
    }
};