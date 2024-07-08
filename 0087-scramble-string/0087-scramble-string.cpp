class Solution {
public:
    
    unordered_map<string,bool> mp;

    bool f(string s1, string s2, int n) {
        if(s1 == s2) return mp[s1+"#"+s2] = true;

        else if(s1.length() == 1) return false;

        else if(mp.find(s1 + "#" + s2) != mp.end())   return mp[s1+"#"+s2];

        for(int k = 1; k <= n-1; k++){
            //If the strings on the left and right side of partition aren't swapped
            bool cond1 = f(s1.substr(0,k), s2.substr(0,k), k) && f(s1.substr(k), s2.substr(k), n-k);

            //If the strings on the left and right of partition are swapped
            bool cond2 = f(s1.substr(0,k), s2.substr(n-k), k) && f(s1.substr(k), s2.substr(0,n-k), n-k);

            if(cond1 || cond2){
                return mp[s1+"#"+s2] = true;
            }
        }

        return mp[s1+"#"+s2] = false;
    }
    
    
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int n = s1.size();
        return f(s1, s2, n);
    }
};