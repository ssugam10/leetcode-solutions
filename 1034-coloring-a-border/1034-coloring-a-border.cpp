class Solution {
public:
    vector<pair<int,int>> internal;
    vector<pair<int,int>> border;
    void fill(vector<vector<int>>& grid, int sr, int sc, int color, int m, int n, int originalColor){
        if(sr < 0 || sr >= m || sc < 0 || sc >= n || grid[sr][sc]!=originalColor)   return;
        grid[sr][sc] = -color;  //color can be already present in matrix before, causing ambiguity

        fill(grid,sr+1,sc,color,m,n,originalColor);
        fill(grid,sr-1,sc,color,m,n,originalColor);
        fill(grid,sr,sc+1,color,m,n,originalColor);
        fill(grid,sr,sc-1,color,m,n,originalColor);

        if(!(sr == m-1 || sc == n-1 || sr == 0 || sc == 0 || grid[sr+1][sc] != -color || grid[sr-1][sc] != -color || grid[sr][sc+1] != -color || grid[sr][sc-1] != -color )){
            internal.push_back({sr,sc});
        }
        else{
            border.push_back({sr,sc});
        }
        
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int originalColor = grid[row][col];
        if(originalColor == color) return grid;

        int m = grid.size();    //rows
        int n = grid[0].size(); //cols
        fill(grid,row,col,color,m,n,originalColor);

        for(auto ele : internal){
            grid[ele.first][ele.second] = originalColor;
        }

        for(auto ele : border){
            grid[ele.first][ele.second] = color;
        }

        return grid;
    }
};