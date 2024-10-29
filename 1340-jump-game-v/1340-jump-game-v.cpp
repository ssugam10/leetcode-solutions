class Solution {
public:
    int n;
    
    int dp[1005];
    
    int f(int i, int d, vector<int> &arr){
        
        int ans = 0;
        
        if(dp[i] != -1) return dp[i];
        
        int k = i + 1;
        while(k < n && k - i <= d && arr[i] > arr[k]){
            ans = max(ans, f(k, d, arr) + 1);
            k++;
        }
        
        k = i - 1;
        while(k >= 0 && i - k <= d && arr[i] > arr[k]){
            ans = max(ans, f(k, d, arr) + 1);
            k--;
        }
        
        return dp[i] = ans;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        
        memset(dp,-1,sizeof(dp));
        
        int mx = 0;
        
        for(int i = 0; i<n; i++){
            mx = max(mx, f(i, d, arr));
        }
        
        return mx + 1;
    }
};