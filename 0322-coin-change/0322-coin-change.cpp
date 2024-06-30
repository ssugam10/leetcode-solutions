class Solution {
    vector<int> dp;
public:
    Solution(){
        dp.resize(10005, -2);
    }
   
    int f(int x, vector<int>& coins)
    {
        if (x == 0)
            return 0;

        if (dp[x] != -2)
            return dp[x];

        int result = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (x - coins[i] < 0)
                continue;
            result = min(result, f(x - coins[i],coins));
        }
        if (result == INT_MAX)
            return dp[x] = INT_MAX;
        return dp[x] = result + 1;
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = f(amount,coins);

        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};