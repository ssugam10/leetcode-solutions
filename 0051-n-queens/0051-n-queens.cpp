class Solution {
public:
    vector<vector<char>> grid;

    vector<vector<string>> ans;

    bool canPlaceQueen(int row, int col, int n){
        //checking for same col
        for(int i = row - 1; i>=0; i--){
            if(grid[i][col] == 'Q') return false;
        }

        //checking for left diagonal
        for(int i = row, j = col; i>=0 && j>=0; i--, j--){
            if(grid[i][j] == 'Q')   return false;
        }

        //checking for right upper diagonal
        for(int i = row, j = col; i>=0 && j < n; i--,j++){
            if(grid[i][j] == 'Q')   return false;
        }

        return true;
    }

    void f(int row, int n){
        if(row == n){
            //You have successfully placed all the n queens, one in each row
            vector<string> configuration(n);
            for(int i =0; i<n; i++){
                for(int j = 0; j<n; j++){
                    configuration[i] += grid[i][j];
                }
            } 
            ans.push_back(configuration);
        }

        for(int i = 0; i<n; i++){
            if(canPlaceQueen(row,i,n)){
                grid[row][i] = 'Q';
                f(row+1,n);
                grid[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        grid.resize(n, vector<char>(n,'.'));
        f(0,n);
        return ans;
    }
};