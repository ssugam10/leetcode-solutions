class Solution {
public:
    int m;  //rows
    int n;  //cols
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    vector<vector<bool>> visited;

    bool hasCycle(int i, int j, int x, int y, char val,vector<vector<char>>& grid){
        visited[i][j] = true;
        
        for(int k = 0; k<4; k++){
            int ro = i + dir[k].first;
            int co = j + dir[k].second;

            if(ro < 0 || ro>=m || co<0 || co>=n || grid[ro][co] != val) continue;

            if(visited[ro][co] && (ro != x || co != y))   return true;

            if(!visited[ro][co]){
                bool res = hasCycle(ro,co,i,j,val,grid);
                if(res) return true;
            }
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visited.clear();
        visited.resize(m, vector<bool>(n,false));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j]){
                    if(hasCycle(i,j,-1,-1,grid[i][j],grid))  return true;
                }
            }
        }

        return false;
    }
};