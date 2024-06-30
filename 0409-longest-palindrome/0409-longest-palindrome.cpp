class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int n = s.length();
        for(int i = 0; i<n; i++){
            mp[s[i]]++;
        }

        int ct = 0;
        bool isOne = false;
        for(auto ele : mp){
            if(ele.second % 2 == 0){
                ct += ele.second;
            }
            else{
                ct += (ele.second - 1);
                isOne = true;
            } 
        }

        if(isOne){
            return ct + 1;
        }
        return ct;
    }
};