class Solution {
public:
    vector<pair<int,int>> moves = {{2,1},{2,-1},{1,2},{1,-2},{-1,-2},{-1,2},{-2,-1},{-2,1}};

    double dp[30][30][105];

    double f(int row, int col, int k, int n){
        if(row >= n || col >= n || row < 0 || col < 0)    return 0;

        if(k == 0)  return 1;

        if(dp[row][col][k] > -0.9)  return dp[row][col][k];

        double ans = 0;
        for(int i = 0; i<8; i++){
            int rowMove = moves[i].first;
            int colMove = moves[i].second;
            ans += f(row+rowMove, col+colMove,k-1, n);
        }
        ans *= 0.125;

        return dp[row][col][k] = ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        memset(dp,-1,sizeof dp);
        return f(row,column,k,n);
    }
};