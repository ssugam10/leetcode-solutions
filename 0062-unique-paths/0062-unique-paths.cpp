class Solution {
public:
    vector<vector<int>> dp;
    int row;
    int col;

    int f(int i, int j){
        if(i == row-1 || j == col - 1){
            return 1;
        }

        if(dp[i][j] != -1)  return dp[i][j];

        int ans = 0;
        if(i+1<row){
            ans = f(i+1,j);
        }

        if(j+1 < col){
            ans += f(i,j+1);
        }

        return dp[i][j] = ans;
    }

    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n,-1));
        row = m;
        col = n;

        return f(0,0);
    }
};