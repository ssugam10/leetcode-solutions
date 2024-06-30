class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int sRow = -1;
        int eRow = -1;
        int sCol = 2000;
        int eCol = -1;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m; j++){
                if(sRow == -1 && grid[i][j] == 1){
                    sRow = i;
                }
                
                if(grid[i][j] == 1){
                    eRow = i;
                    eCol = max(eCol,j);
                    sCol = min(sCol,j);
                }
                
            }
        }
        
        //cout<<sRow<<" "<<eRow<<" "<<sCol<<" "<<eCol<<endl;
        
        int area = (eRow - sRow + 1) * (eCol - sCol + 1);
        return area;
    }
};