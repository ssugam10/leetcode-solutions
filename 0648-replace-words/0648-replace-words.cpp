class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans = "";

        unordered_set<string> s;
        for(int i = 0 ; i<dictionary.size(); i++){
            s.insert(dictionary[i]);
        }

        int n = sentence.length();
        bool ok = false;
        string word = "";
        for(int i = 0; i<n; i++){
            if(sentence[i] == ' '){
                if(!ok) ans += word;
                ans += " ";
                word = "";
                ok = false;
                continue;
            }
            
            if(ok)  continue;
            else word += sentence[i];

            if(s.find(word) != s.end()){
                ok = true;
                ans += word;
            }
        }

        if(!ok) ans += word;

        return ans;
    }
};