class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        unordered_map<char,vector<int>> mp; // maps the non star char to their indices
        unordered_set<int> indices; //holds the indices to be removed
        set<char> sat; //holds the charaacters in sorted order
        
        for(int i = 0; i<n; i++){
            if(s[i] == '*'){
                indices.insert(i);  //star to be removed
                indices.insert(mp[*(sat.begin())][mp[*(sat.begin())].size() - 1]);  //the smallest char before start must be removed
                mp[*(sat.begin())].pop_back();
                
                if(mp[*(sat.begin())].size() == 0){
                    sat.erase(sat.begin());
                }
            }
            else{
                mp[s[i]].push_back(i);
                sat.insert(s[i]);
            }
        }
        
        string newStr = "";
        for(int i = 0; i<n ; i++){
            if(indices.find(i) == indices.end()){
                newStr += s[i];
            }
        }
        
        return newStr;
        
    }
};