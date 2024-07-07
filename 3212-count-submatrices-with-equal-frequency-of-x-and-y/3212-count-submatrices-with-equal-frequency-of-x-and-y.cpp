class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<pair<int,int>>> pre(n, vector<pair<int,int>>(m, {0,0}));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 'X'){
                    pre[i][j].first = 1;
                }
                else if(grid[i][j] == 'Y'){
                    pre[i][j].second = 1;
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 1; j<m; j++){
                pre[i][j].first += pre[i][j-1].first;
                pre[i][j].second += pre[i][j-1].second;
            }
        }
        
        //For each {i,j} we have how many X's and Y's are present in that row till jth column
        
        for(int i = 0; i<m; i++){
            for(int j = 1; j<n; j++){
                pre[j][i].first += pre[j-1][i].first;
                pre[j][i].second += pre[j-1][i].second;
            }
        }
        
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j= 0; j<m; j++){
                if(pre[i][j].first == pre[i][j].second && pre[i][j].first > 0){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};