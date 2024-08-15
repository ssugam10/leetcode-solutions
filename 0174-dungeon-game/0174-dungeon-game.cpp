class Solution {
public:
    //dp[i][j] represents the minimum hp required to reach (n-1,m-1)
    
    vector<vector<int>> dp;
    
    int f(int i, int j, vector<vector<int>>& dungeon){
        
        if(i >= dungeon.size() || j >= dungeon[0].size())   return INT_MAX;
        
        if(i == dungeon.size() - 1 && j == dungeon[0].size() - 1)   return (dungeon[i][j] <= 0) ? -dungeon[i][j] : 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int ans = min(f(i+1,j,dungeon), f(i,j+1,dungeon)) - dungeon[i][j];
        
        if(ans <= 0) ans = 0;
        
        return dp[i][j] = ans;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        dp.resize(n,vector<int>(m,-1));
        return max(1,1 + f(0,0,dungeon));
    }
};