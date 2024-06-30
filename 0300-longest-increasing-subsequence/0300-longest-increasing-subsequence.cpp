class Solution {
public:
    vector<int> dp;
    // int f(int i, vector<int>& arr){

    //     if(i==0)    return 1;

    //     if(dp[i] != -1) return dp[i];

    //     int ans = 0;
    //     for(int j = 0; j<i; j++){
    //         if(arr[j] < arr[i]){
    //             ans = max(ans,f(j,arr));
    //         }
    //     }

    //     return dp[i] = ans + 1;
    // }


    int fbu(vector<int>& arr){
        dp.clear();
        dp.resize(2505,-1);
        dp[0] = 1;
        int n = arr.size();

        int final_ans = 0;
        for(int i = 0; i<n; i++){
            int ans = 0;
            for(int j = 0; j<i; j++){
                if(arr[j] < arr[i]){
                    ans = max(ans,dp[j]);
                }
            }
            dp[i] = ans + 1;
            final_ans = max(final_ans, dp[i]);
        }

        return final_ans;
    }
    int lengthOfLIS(vector<int>& nums) {

        return fbu(nums);
    }
};