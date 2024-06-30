class Solution {
public:
    vector<pair<int,int>> dist = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int n = grid.size();

        if(grid[0][0] == 1) return -1;

        q.push({{0,0},1});

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();

            if(row == n - 1 && col == n-1)    return distance;

            for(int k = 0; k<8; k++){
                int ro = row + dist[k].first;
                int co = col + dist[k].second;

                if(ro < 0 || co < 0 || ro >= n || co >= n || grid[ro][co] != 0) continue;

                q.push({{ro,co},distance+1});
                grid[ro][co] = 1;
            }
        }

        return -1;
    }
};