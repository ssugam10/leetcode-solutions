class Solution {
public:
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    int m;  // rows
    int n;  // cols

    void bfsP(vector<vector<int>>& heights) {
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            pacific[i][0] = true;
            q.push({i, 0});
        }
        for (int i = 1; i < n; i++) {
            pacific[0][i] = true;
            q.push({0, i});
        }

        vector<int> dirs = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int r = row + dirs[i];
                int c = col + dirs[i + 1];
                if (r >= 0 && r < m && c >= 0 && c < n && !pacific[r][c] && heights[r][c] >= heights[row][col]) {
                    pacific[r][c] = true;
                    q.push({r, c});
                }
            }
        }
    }

    void bfsA(vector<vector<int>>& heights) {
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            atlantic[i][n - 1] = true;
            q.push({i, n - 1});
        }
        for (int i = 0; i < n; i++) {
            atlantic[m - 1][i] = true;
            q.push({m - 1, i});
        }

        vector<int> dirs = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int r = row + dirs[i];
                int c = col + dirs[i + 1];
                if (r >= 0 && r < m && c >= 0 && c < n && !atlantic[r][c] && heights[r][c] >= heights[row][col]) {
                    atlantic[r][c] = true;
                    q.push({r, c});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};

        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> ans;

        pacific.assign(m, vector<bool>(n, false));
        atlantic.assign(m, vector<bool>(n, false));

        bfsP(heights);
        bfsA(heights);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
