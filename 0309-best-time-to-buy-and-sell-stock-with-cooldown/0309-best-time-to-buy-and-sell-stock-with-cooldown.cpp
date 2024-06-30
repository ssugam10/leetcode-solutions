class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int on, vector<int> &prices){  // on == 1 means transactions is ongoing ans you cannot buy rn

        if(i >= prices.size())  return 0;

        if(dp[i][on] != -1) return dp[i][on];

        int ans = f(i+1,on,prices);

        if(on == 1){
            ans = max(ans, prices[i] + f(i+2,0,prices));
        }
        else{
            ans = max(ans, f(i+1,1,prices) - prices[i]);
        }

        return dp[i][on] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.clear();
        dp.resize(n+1,vector<int>(2,-1));
        return f(0,0,prices);
    }
};