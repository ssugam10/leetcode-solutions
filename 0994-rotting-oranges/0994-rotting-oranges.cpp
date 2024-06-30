class Solution {
public:
    int m;
    int n;
    int countUnrotten;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    int bfs(vector<vector<int>>& grid, queue<pair<pair<int,int>,int>>& q){
        int minute = 0;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            minute = max(minute,time);

            for(int i = 0; i<4; i++){
                int ro = row + dir[i][0];
                int co = col + dir[i][1];

                if(ro < 0 || ro >= m || co < 0 || co >= n || grid[ro][co] != 1) continue;
                

                grid[ro][co] = 2;
                countUnrotten--;
                q.push({{ro,co},time+1});
            }
        }

        if(countUnrotten){
            return -1;
        }
        return minute;
        
    }

    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        queue<pair<pair<int,int>,int>> q;

        countUnrotten = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1) countUnrotten++;
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }

        int minute = bfs(grid,q);
        return minute;
    }
};