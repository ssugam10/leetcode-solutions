#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    bool vis[55][55];
    int dp[55][55][105];

    bool check(vector<vector<int>>& grid, int row, int col, int hlt) {
        int m = grid.size(); 
        int n = grid[0].size();

        // Boundary conditions and health check
        if (row >= m || col >= n || row < 0 || col < 0 || hlt <= 0 || vis[row][col]) 
            return false;
        
        // Check if reached the destination
        if (row == m - 1 && col == n - 1) {
            return hlt > grid[row][col];
        }

        // Check memoization table
        if (dp[row][col][hlt] != -1) 
            return dp[row][col][hlt] == 1;

        vis[row][col] = true; // Mark the current cell as visited
        
        // Recursive calls to explore all four directions
        bool up = check(grid, row - 1, col, hlt - grid[row][col]);
        bool dw = check(grid, row + 1, col, hlt - grid[row][col]);
        bool lf = check(grid, row, col - 1, hlt - grid[row][col]);
        bool rf = check(grid, row, col + 1, hlt - grid[row][col]);

        vis[row][col] = false; // Unmark the current cell
        
        // Combine results from all directions
        bool result = up || dw || lf || rf;
        
        // Update memoization table
        dp[row][col][hlt] = result ? 1 : 0;

        return result;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Initialize memoization table
        memset(dp, -1, sizeof(dp));
        memset(vis, false, sizeof(vis));

        return check(grid, 0, 0, health);
    }
};
