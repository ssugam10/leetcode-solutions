class Solution {
public:
    vector<vector<int>> dp;
    
//     int f(int i, int j, vector<int> &cuts){
        
//         if(i > j)   return 0;
        
//         if(dp[i][j] != -1)  return dp[i][j];
        
//         int ans = INT_MAX;
//         int len = cuts[j+1] - cuts[i-1];
//         for(int k = i ; k <= j; k++){
//             ans = min(ans, f(i,k-1,cuts) + f(k+1,j,cuts));
//         }
        
//         return dp[i][j] = ans + len;
//     }
    
    int fbu(vector<int> &cuts, int n){
        dp.clear();
        dp.resize(205,vector<int>(205,0));
        
        for(int i = n; i>=1; i--){
            for(int j = 1; j <= n; j++){
                if(i > j)   continue;
                
                dp[i][j] = INT_MAX;
                
                for(int k = i ; k <= j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k+1][j]);
                }
                
                dp[i][j] += (cuts[j+1]-cuts[i-1]);
            }
        }
        
        return dp[1][n];
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        sort(cuts.begin(),cuts.end());
        
        vector<int> cutting;
        cutting.push_back(0);
        
        for(int i = 0; i<cuts.size(); i++){
            cutting.push_back(cuts[i]);
        }
        
        cutting.push_back(n);
        
        return fbu(cutting, cutting.size()-2);
        
        
        // dp.clear();
        // dp.resize(205,vector<int>(205,-1));
        
        //return f(1,cutting.size() - 2,cutting);
    }
};