class Solution {
public:
    int n;
    int dp[55];
    
    int f(string &s, int i, set<string> &st){
        
        if(i >= n)  return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int mx = INT_MAX;
        
        for(int k = i; k<n; k++){
            if(st.find(s.substr(i, k - i + 1)) != st.end()){
                mx = min(mx, f(s,k+1,st));
            }
        }
        
        mx = min(mx, 1 + f(s,i+1,st));
        // if(mx == INT_MAX){
        //     return 1 + f(s,i+1,st);
        // }
        
        return dp[i] = mx;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> st(dictionary.begin(),dictionary.end());
        n = s.length();    
        
        memset(dp,-1,sizeof(dp));
        
        return f(s,0,st);
    }
};