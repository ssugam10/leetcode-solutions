class Solution {
public:
    int dp[100005][2];

    int f(vector<int>& prices, int i, bool on){

        if(i == prices.size())  return 0;

        if(dp[i][on] != -1)  return dp[i][on];

        int ans = INT_MIN;
        ans = f(prices,i+1,on);

        if(on == true){
            ans = max(ans,f(prices,i+1,false) + prices[i]);
        }

        else{
            ans = max(ans, f(prices,i+1,true) - prices[i]);
        }
        
        return dp[i][on] = ans;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        int ans = f(prices,0,false);
        if(ans<0)   return 0;
        return ans;
    }
};