class Solution {
public:
    int fees;
    vector<vector<int>> dp;
    int f(int i, bool on, vector<int>& prices){

        if(i == prices.size())  return 0;

        if(dp[i][on] != -1) return dp[i][on];

        int ans = f(i+1,on,prices);

        if(on){
            ans = max(ans, f(i+1,false,prices) + prices[i] - fees);
        }
        else{
            ans = max(ans, f(i+1,true,prices) - prices[i]);
        }

        return dp[i][on] = ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        fees = fee;
        int n = prices.size();
        dp.clear();
        dp.resize(n+1,vector<int>(2,-1));
        return f(0,false,prices);
    }
};