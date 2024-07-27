class Solution {
public:
    int n;
    
    vector<int> dp;
    
    int f(int i, vector<int> &values){
        
        if(i >= n)  return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int ans = INT_MIN;
        int tot = 0;
        for(int k = i; k < min(i+3,n); k++){
            if(k >= n)  break;
            tot += values[k];
            ans = max(ans, tot - f(k+1,values));
        }
        
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        
        dp.assign(n+1,-1);
        
        int ans = f(0,stoneValue);
        
        if(ans == 0)    return "Tie";
        else if(ans > 0)    return "Alice";
        else return "Bob";
    }
};