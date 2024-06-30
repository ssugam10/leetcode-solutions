class Solution {
public:
    vector<vector<char>> ans;
    bool found = false;

    bool canFill(int i, int j, char k, vector<vector<char>>& board){
        for(int l = 0; l < 9; l++){
            if(k == board[i][l]) return false;
        }

        for(int l = 0; l < 9; l++){
            if(k == board[l][j]) return false;
        }        

        int row = (i/3) * 3;
        int col = (j/3) * 3;

        for(int r = row; r < row + 3; r++){
            for(int c = col; c < col + 3; c++){
                if(k == board[r][c]) return false;
            }
        }

        return true;
    }

    void fill(int i, int j, vector<vector<char>>& board){
        if(found) return;  // If solution is found, return immediately.

        if(i == 9){
            ans = board;
            found = true;
            return;
        }

        if(board[i][j] != '.'){
            if(j == 8){
                fill(i + 1, 0, board);
            } else {
                fill(i, j + 1, board);
            }
        } else {
            for(char k = '1'; k <= '9'; k++){
                if(canFill(i, j, k, board)){
                    board[i][j] = k;
                    if(j == 8){
                        fill(i + 1, 0, board);
                    } else {
                        fill(i, j + 1, board);
                    }
                    if(found) return;  // Check again before backtracking.
                    board[i][j] = '.';
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        fill(0, 0, board);
        board = ans;
    }
};
