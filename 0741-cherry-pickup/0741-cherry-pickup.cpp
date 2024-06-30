#define ll long long int
class Solution {
public:

    int n;          // dimenions of the i/p matrix 
    vector<vector<int>> mat; // input matrix

    int dp[55][55][55];

    int f(int i, int j, int x, int y)
    {

        if (i > n-1 || j > n-1 || x > n-1 || y > n-1 || mat[i][j] == -1 || mat[x][y] == -1)
            return INT_MIN;

        if (i == n-1 && j == n-1)   //both the tourists have reached the last cell in grid
        {
            return mat[i][j] == 1;
        }

        if (dp[i][j][x] != -1)
            return dp[i][j][x];

        int result = INT_MIN;

        result = max(result, f(i + 1, j, x + 1, y));
        result = max(result, f(i + 1, j, x, y + 1));
        result = max(result, f(i, j + 1, x + 1, y));
        result = max(result, f(i, j + 1, x, y + 1));

        if(result == INT_MIN){  //no path exists from current cell to end cell
            return dp[i][j][x] = INT_MIN;
        }

        result += (mat[i][j] == 1);
        result += (mat[x][y] == 1);

        // remove repetition
        if (i == x && j == y && mat[i][j] == 1)
            result--;

        return dp[i][j][x] = result;
    }


    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof dp);
        mat.clear();

        n = grid.size();
        mat = grid;
        
        int ans = f(0,0,0,0);
        //cout<<ans<<endl;
        return (ans == INT_MIN) ? 0 : ans;
    }
};