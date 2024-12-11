class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        
        vector<int> len(n,0);   //stores the length of longest special substr ending at s[i]
        len[0] = 1;
        
        for(int i = 1; i<n; i++){
            if(s[i] == s[i - 1]){
                len[i] = len[i - 1] + 1;
            }
            else len[i] = 1;
        }
        
        map<char,priority_queue<int>> mp;   //stores the length of special substrings of all groups
        
        for(int i = 0; i<n; i++){
            mp[s[i]].push(len[i]);
        }
        
        int ans = -1;
        
        for(auto &ele : mp){
            if(ele.second.size() >= 3){
                ele.second.pop();
                ele.second.pop();
                ans = max(ans,ele.second.top());
            }
        }
        
        return ans;
    }
};