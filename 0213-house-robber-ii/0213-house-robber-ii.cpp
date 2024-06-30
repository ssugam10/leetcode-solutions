class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int> &arr, int i){ //0 is not robbed
        if(i == arr.size() - 1 )     return arr[i];
        if(i == arr.size() - 2)     return max(arr[i],arr[i+1]);
        if(i >= arr.size()) return 0;

        if(dp[i][1] != -1)     return dp[i][1];   //ith state is already computed

        return dp[i][1] = max(f(arr,i+1), arr[i] + f(arr,i+2));

    }

    int f1(vector<int> &arr, int i){    //0 is robbed
        if(i == arr.size() - 1)     return 0;
        if(i == arr.size() - 2)     return arr[i];
        if(i >= arr.size()) return 0;

        if(dp[i][0] != -1)     return dp[i][0];   //ith state is already computed

        return dp[i][0] = max(f1(arr,i+1), arr[i] + f1(arr,i+2));

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.clear();
        dp.resize(n,vector<int>(2,-1));

        int firstNotRobbed = f(nums,1);
        int firstRobbed = nums[0] + f1(nums,2);
        // cout<<n<<endl;
        // cout<<firstNotRobbed<<endl;
        // cout<<firstRobbed<<endl;

        return max(firstNotRobbed,firstRobbed);
    }
};