class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    int f(int i, int j, string &s, string &t){
        
        if(i == n || j == n)    return 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        if(s[i] == t[j]){
            return dp[i][j] = 1 + f(i+1,j+1,s,t);
        }
        
        return dp[i][j] = max(f(i+1,j,s,t), f(i,j+1,s,t));
    }
    
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        
        n = s.length();
        
        dp.clear();
        dp.resize(n+1,vector<int>(n+1,-1));
        
        return n - f(0,0,s,t);
    }
};