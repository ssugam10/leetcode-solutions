class Solution {
public:
    int n;
    vector<int> dp;
    int f(int i, vector<int> &arr, int k){
        if(i >= n)  return 0;
        
        if(dp[i] != -1) return dp[i];
        int mx = -1;
        int sum = 0;
        for(int j = i; j < min(n,i+k); j++){
            mx = max(mx, arr[j]);
            sum = max(sum, mx * (j - i + 1) + f(j + 1, arr, k));
        }
        
        return dp[i] = sum;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        dp.assign(n+1,-1);
        return f(0,arr,k);
    }
};