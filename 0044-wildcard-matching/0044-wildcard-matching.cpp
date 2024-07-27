class Solution {
public:
    int n;
    int m;
    
    int dp[2005][2005];
    
    bool f(string s, string p, int i, int j){
        
        if(i == n && j == m)    return true;
        
        if(j == m - 1 && p[j] == '*') return true;
        
        if(i > n || j > m)    return false;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        bool ans = false;
        if((i < n && j < m) && (s[i] == p[j] || p[j] == '?')){
            ans = ans || f(s,p,i+1,j+1);
        }
        else if(p[j] != '*'){
            return false;
        }
        
        if(p[j] == '*'){
            ans = ans || f(s,p,i,j+1);
            ans = ans || f(s,p,i+1,j);
        }
        
        return dp[i][j] = ans;
    }
    
    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();
        
        memset(dp,-1,sizeof(dp));
        
        return f(s,p,0,0);
    }
};