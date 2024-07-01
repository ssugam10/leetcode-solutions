class Solution {
public:
    vector<vector<int>> dp;
    
    int f(int i, int j, vector<int> &cuts){
        
        if(i > j)   return 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int ans = INT_MAX;
        int len = cuts[j+1] - cuts[i-1];
        for(int k = i ; k <= j; k++){
            ans = min(ans, f(i,k-1,cuts) + f(k+1,j,cuts));
        }
        
        return dp[i][j] = ans + len;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        sort(cuts.begin(),cuts.end());
        
        vector<int> cutting;
        cutting.push_back(0);
        
        for(int i = 0; i<cuts.size(); i++){
            cutting.push_back(cuts[i]);
        }
        
        cutting.push_back(n);
        
        
        
        dp.clear();
        dp.resize(205,vector<int>(205,-1));
        
        return f(1,cutting.size() - 2,cutting);
    }
};