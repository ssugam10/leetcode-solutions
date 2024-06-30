class Solution {
public:
    int m; //rows
    int n; //cols

    vector<vector<int>> dist = {{1,0},{-1,0},{0,1},{0,-1}};

    vector<vector<int>> bfs(vector<vector<int>>& mat, queue<pair<int,int>>& q){
        vector<vector<int>> ans(m, vector<int>(n,0));

        int distance = 1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(row == -1 && col == -1){
                if(q.empty()){
                    continue;
                }
                q.push({-1,-1});
                distance++;
                continue;
            }

            for(int i = 0; i<4; i++){
                int ro = row + dist[i][0];
                int co = col + dist[i][1];

                if(ro < 0 || ro >= m || co < 0 || co > n-1 || mat[ro][co] == 0) continue;

                q.push({ro,co});
                mat[ro][co] = 0;
                ans[ro][co] = distance;
            }
        }

        return ans;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();

        queue<pair<int,int>> q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        q.push({-1,-1});

        return bfs(mat,q);
    }
};