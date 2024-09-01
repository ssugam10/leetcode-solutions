class Solution {
public:
    
    int dp[105][1025];
    
    int f(int i, int mask, vector<vector<int>> &vp){
        if(i == vp.size())  return 0;
        
        if(dp[i][mask] != -1)   return dp[i][mask];
        
        int row = vp[i][1];
        
        int ans = 0;
        
        if((1 << row) & mask){  //This row is already selected so move on
            ans = f(i+1,mask,vp);
        }
        else{   //If this row isnt selected, we take max of two options : 1. taking curr value, 2. trying to take other value 
            int j = i + 1;
            while(j < vp.size() && vp[j][0] == vp[i][0]){
                j++;
            }
            
            int ans1 = vp[i][0] + f(j, mask | (1 << row), vp); // since we cannot take duplicate values, we skip them using j
            int ans2 = f(i + 1, mask, vp);
            
            ans = max(ans1,ans2);
        }
        
        return dp[i][mask] = ans;
    }
    
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vp;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                vp.push_back({grid[i][j],i});
            }
        }
        
        sort(vp.begin(),vp.end());
        
        memset(dp,-1,sizeof(dp));
        
        return f(0,0,vp);
    }
};