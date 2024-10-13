class Solution {
public:
    int n;
    int mod = 1e9 + 7;
    
    vector<char> v = {'F', 'W', 'E'};
    
    int dp[1005][2005][4];
    
    int f(int i, int points, int call, string &s) {
        if (i == n) {
            if (points > 0) return 1;
            else return 0;
        }
        
        if (dp[i][points + 1000][call] != -1) 
            return dp[i][points + 1000][call];
        
        int cnt = 0;
        
        if (s[i] == 'F') {
            if (call != 0) cnt = (cnt % mod + f(i+1, points, 0, s) % mod) % mod;
            if (call != 1) cnt = (cnt % mod + f(i+1, points + 1, 1, s) % mod) % mod;
            if (call != 2) cnt = (cnt % mod + f(i+1, points - 1, 2, s) % mod) % mod;
        }
        else if (s[i] == 'W') {
            if (call != 0) cnt = (cnt % mod + f(i+1, points - 1, 0, s) % mod) % mod;
            if (call != 1) cnt = (cnt % mod + f(i+1, points, 1, s) % mod) % mod;
            if (call != 2) cnt = (cnt % mod + f(i+1, points + 1, 2, s) % mod) % mod;
        }
        else {
            if (call != 0) cnt = (cnt % mod + f(i+1, points + 1, 0, s) % mod) % mod;
            if (call != 1) cnt = (cnt % mod + f(i+1, points - 1, 1, s) % mod) % mod;
            if (call != 2) cnt = (cnt % mod + f(i+1, points, 2, s) % mod) % mod;
        }
        
        return dp[i][points + 1000][call] = cnt;
    }
    
    int countWinningSequences(string s) {
        n = s.length();    
        
        memset(dp, -1, sizeof(dp));
        
        return f(0, 0, 3, s) ;
    }
};
