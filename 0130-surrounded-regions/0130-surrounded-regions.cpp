class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(int i, int j, vector<vector<char>>& board) {
        visited[i][j] = true;

        for (auto dir : directions) {
            int row = i + dir[0];
            int col = j + dir[1];

            if (row >= 0 && row < m && col >= 0 && col < n && !visited[row][col] && board[row][col] == 'O') {
                dfs(row, col, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        m = board.size();
        n = board[0].size();
        visited.resize(m, vector<bool>(n, false));

        // Mark all 'O's on the border and connected to the border
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O' && !visited[i][0]) dfs(i, 0, board);
            if (board[i][n-1] == 'O' && !visited[i][n-1]) dfs(i, n-1, board);
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O' && !visited[0][j]) dfs(0, j, board);
            if (board[m-1][j] == 'O' && !visited[m-1][j]) dfs(m-1, j, board);
        }

        // Flip all unvisited 'O's to 'X'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
