#define pip pair<int,pair<int,int>>

class Solution {
public:
    int m;  // rows
    int n;  // cols

    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        deque<pair<int,int>> dq;
        dq.push_back({0,0});
        dist[0][0] = 0;

        while (!dq.empty()) {
            auto curr = dq.front();
            dq.pop_front();
            int x = curr.first;
            int y = curr.second;
            int direction = grid[x][y];

            for(int i = 0; i<4; i++){
                int ro = x + dir[i].first;
                int co = y + dir[i].second;

                int edgeW = 1;
                if(i + 1 == direction)   edgeW = 0;

                if(ro < m && co < n && ro >=0 && co >=0){
                    if(dist[ro][co] > dist[x][y] + edgeW){
                        dist[ro][co] = dist[x][y] + edgeW;
                        if(edgeW == 1){
                            dq.push_back({ro,co});
                        }
                        else{
                            dq.push_front({ro,co});
                        }
                    }
                }
            }

        }

        return dist[m - 1][n - 1];
    }
};
