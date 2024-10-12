class Solution {
public:
    int n,m;
    int dp[3005][3005];
    
    set<int> indices;
    
    int f(int i, int j, string &s, string &p){
        if(i == n){
            if(j == m){
                return 0;
            }
            
            return INT_MIN;
        }
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int ans = f(i+1,j,s,p); //just ignore the current element
        
        //If it is possible to delete current idx, then try to del it
        if(indices.find(i) != indices.end()){
            ans = max(ans, 1 + f(i + 1, j, s, p));
        }
        
        //If matching is found then consider to move both pointers forward
        if(s[i] == p[j]){
            ans = max(ans, f(i + 1, j + 1, s, p));
        }
        
        return dp[i][j] = ans;
    }
    
    
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        n = source.length();
        m = pattern.length();
        
        memset(dp,-1,sizeof(dp));
        
        for(auto ele : targetIndices){
            indices.insert(ele);
        }
        
        return f(0,0,source,pattern);
    }
};