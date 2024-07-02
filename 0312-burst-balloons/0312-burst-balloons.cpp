class Solution {
public:
    vector<vector<int>> dp;
    
//     int f(vector<int> &nums, int i, int j){
        
//         if(i > j)   return 0;
        
//         if(dp[i][j] != -1)  return dp[i][j];
        
//         int coins = -1;
//         for(int k = i ; k<=j; k++){
//             int gain = nums[i-1] * nums[k] * nums[j+1];
//             coins = max(coins,f(nums,i,k-1) + gain + f(nums,k+1,j));
//         }
        
//         return dp[i][j] = coins;
//     }
    
    int fbu(vector<int> &nums){
        dp.clear();
        dp.resize(305,vector<int>(305,0));
        int n = nums.size() - 2;
        
        for(int len = 1; len <= n; len++){
            for(int i = 1; i + len - 1 <= n; i++){
                int j = i+len-1;    //last index
                dp[i][j] = -1;
                for(int k = i ; k<=j; k++){
                    int gain = nums[i-1] * nums[k] * nums[j+1];
                    dp[i][j] = max(dp[i][j] , dp[i][k-1] + gain + dp[k+1][j]);
                }
            }
        }
        
        return dp[1][n];
    }
    
    int maxCoins(vector<int>& nums) {
        vector<int> numbers;
        numbers.push_back(1);
        
        int n = nums.size();
        // dp.clear();
        // dp.resize(305,vector<int>(305,-1));
        
        for(int i = 0; i<n; i++){
            numbers.push_back(nums[i]);
        }
        
        numbers.push_back(1);
        
        // return f(numbers,1,n);
        
        return fbu(numbers);
    }
};