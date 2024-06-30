class Solution {
public:
//     vector<int> dp;

//     int f(int i, vector<int>& arr){
//         if(i == 0 || i == 1)    return 0;

//         if(dp[i] != -1) return dp[i];

//         if(2 * arr[i-1] == arr[i] + arr[i-2]){
//             return dp[i] = f(i-1,arr) + 1;
//         }

//         else return dp[i] = 0;
//     }

//     int numberOfArithmeticSlices(vector<int>& nums) {
//         dp.clear();
//         dp.resize(5005,-1);
//         int sum = 0;
//         for(int i = 2; i<nums.size(); i++){
//             sum += f(i,nums);
//         }

//         return sum;
//     }
    vector<int> dp;

    int fbu(vector<int>& arr){
        dp[0] = 0;
        dp[1] = 0;

        int n = arr.size();
        int sum = 0;
        for(int i = 2; i<n ; i++){
            if(2 * arr[i-1] == arr[i] + arr[i-2]){
                dp[i] = dp[i-1] + 1;
            }
            else{
                dp[i] = 0;
            }

            sum += dp[i];
        }

        return sum;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        dp.clear();
        dp.resize(5005,-1);

        return fbu(nums);
    }
};