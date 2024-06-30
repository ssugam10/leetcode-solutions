class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;

        int n = strs.size();
        for(int i = 0; i<n; i++){
            string lexo = strs[i];
            sort(lexo.begin(),lexo.end());
            mp[lexo].push_back(strs[i]);
        }

        for(auto ele : mp){
            ans.push_back(ele.second);
        }

        return ans;
    }
};