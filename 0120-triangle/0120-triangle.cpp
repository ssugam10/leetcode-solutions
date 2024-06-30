class Solution {
public:
    vector<vector<int>> dp;

    // int f(int i, int j, vector<vector<int>>& triangle){

    //     if(i == triangle.size())    return 0;

    //     if(dp[i][j] != -1)  return dp[i][j];

    //     return dp[i][j] = min(f(i+1,j,triangle), f(i+1,j+1,triangle)) + triangle[i][j];
    // }

    int fbu(vector<vector<int>>& triangle){
        dp.clear();
        dp.resize(205,vector<int>(205,0));

        int n = triangle.size();

        for(int i = n-1; i>=0; i--){
            for(int j = i; j>=0; j--){
                dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j];
            }
        }

        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        // dp.clear();
        // dp.resize(205,vector<int>(205,-1));
        return fbu(triangle);
    }
};