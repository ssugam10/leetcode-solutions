class Solution {
public:
    int n;
    int m;
    
    
    vector<vector<int>> dp;
    
    int f(int i, int j, string &s, string &t){
        
        if(j == m)    return 1;
        
        if(i == n)  return 0;
        
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int ans = 0;
        if(s[i] == t[j]){
            ans += f(i+1,j+1,s,t);
        }
        
        ans += f(i+1,j,s,t);
        
        return dp[i][j] = ans;
    }
    
    int numDistinct(string s, string t) {
        n = s.length();
        m = t.length();
        
        dp.clear();
        dp.resize(n+1,vector<int>(m+1,-1));
        
        return f(0,0,s,t);
    }
};