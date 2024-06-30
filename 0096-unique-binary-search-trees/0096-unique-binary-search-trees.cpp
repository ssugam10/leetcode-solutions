class Solution {
public:
    vector<int> dp;
    int f(int n){
        if(n==0 || n==1)    return 1;
        if(n==2)    return 2;

        if(dp[n]!= -1)  return dp[n];
        int sum = 0;
        for(int k = 1; k <= n; k++){
            //k is potential root
            sum += f(k-1)*f(n-k);
        }

        return dp[n] = sum;
    }
    int numTrees(int n) {
        dp.clear();
        dp.resize(30,-1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int len = 3; len <=n; len++){
            int sum = 0;
            for(int i = 1; i<=len; i++){
                sum += dp[i-1] * dp[len-i];
            }
            dp[len] = sum;
        }

        return dp[n];
    }
};