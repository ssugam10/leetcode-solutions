class Solution {
public:
    vector<vector<int>> dp;
    
    bool f(int i, int jump, vector<int> &stones){
        
        if(i == stones.size() - 1)  return true;
        
        if(dp[i][jump] != -1)  return dp[i][jump];
        
        bool isPossible = false;
        
        int find = max(1 + stones[i], stones[i] + jump - 1);
        
        auto it = lower_bound(stones.begin(),stones.end(),find);
        if(it == stones.end())  return false;
    
        auto iterate = it - stones.begin();
        
        while(iterate < stones.size() && stones[iterate] <= stones[i] + jump + 1){
            isPossible = isPossible || f(iterate,stones[iterate] - stones[i],stones);
            iterate++;
        }
        
        return dp[i][jump] = isPossible;
    }
    
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1)  return false;
        
        int n = stones.size();
        
        dp.resize(n+1,vector<int>(n+1,-1));
        
        return f(1,1,stones);
    }
};