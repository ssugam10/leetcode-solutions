class Solution {
public:
    int n;
    int m;
    
    vector<vector<int>> dp;
    
    int f(int i, int j, string &s, string &t){
        
        if(i == n || j == m)    return 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        if(s[i] == t[j]){
            return dp[i][j] = 1 + f(i+1,j+1,s,t);
        }
        
        return dp[i][j] = max(f(i+1,j,s,t), f(i,j+1,s,t));
    }
    
    int minDistance(string word1, string word2) {
        n = word1.length();
        m = word2.length();
        
        dp.clear();
        dp.resize(n+1,vector<int>(m+1,-1));
        
        int len = f(0,0,word1,word2);
        
        return n + m - 2 * len;
    }
};