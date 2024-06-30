class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        vector<string> result;

        string word = "";
        for(int i = 0; i<n; i++){
            char ch = s[i];
            if(ch == ' '){
                if(word.length() > 0){
                    result.push_back(word);
                    word = "";
                }
            }
            else{
                word += ch;
            }
        }

        if(word.length() > 0) result.push_back(word);

        int m = result.size();
        string ans = result[m-1];
        for(int i = m-2; i>=0; i--){
            ans += (" " + result[i]);
        }

        return ans;
    }
};