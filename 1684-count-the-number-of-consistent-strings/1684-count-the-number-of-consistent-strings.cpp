class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = allowed.length();
        
        unordered_set<char> s;
        
        for(int i = 0; i<n; i++){
            s.insert(allowed[i]);
        }
        
        int ct = 0;
        
        int m = words.size();
        for(int i = 0; i<m; i++){
            bool flag = true;
            for(int j = 0; j<words[i].length(); j++){
                if(s.find(words[i][j]) == s.end()){
                    flag = false;
                    break;
                }
            }
            
            if(flag){
                ct++;
            }
        }
        
        return ct;
    }
};