class Solution {
public:
    vector<vector<int>> dp;

    int f(int i, int t, vector<int> &coins){
        if(t == 0)  return 1;

        if(i == coins.size())   return 0;

        if(dp[i][t] != -1)  return dp[i][t];

        int ans = 0;

        ans += f(i+1,t,coins);

        if(coins[i] <= t){
            ans += f(i,t-coins[i],coins);
        }

        return dp[i][t] = ans;
    }

    int change(int amount, vector<int>& coins) {
        dp.clear();
        dp.resize(coins.size()+1, vector<int>(amount+1,-1));
        return f(0,amount,coins);
    }
};