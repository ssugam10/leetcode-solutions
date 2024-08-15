class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size() ;
        vector<vector<int>> indegree(m , vector(n , 0)) ;
        vector dir = {-1,0,1,0,-1} ;

        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                for (int k = 0 ; k < 4 ; k++) {
                    int next_i = i + dir[k] ; 
                    int next_j = j + dir[k+1] ; 
                    if (next_i >= 0 && next_j >= 0 && next_i < m && next_j < n 
                        && matrix[next_i][next_j] > matrix[i][j]) {
                        indegree[next_i][next_j]++ ; 
                    }
                }
            }
        }

        queue<pair<int,int>> Q ;

        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (indegree[i][j] == 0) {
                    Q.push({i,j}) ; 
                }
            }
        }

        int maxlen = 0 ;

        while (!Q.empty()) {
            int size = Q.size() ; 
            for (int i = 0 ; i < size ; i++) {
                auto [ x , y ] = Q.front() ; Q.pop() ; 
                for (int k = 0 ; k < 4 ; k++) {
                    int nx = x + dir[k] ; 
                    int ny = y + dir[k+1] ; 
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && matrix[nx][ny] > matrix[x][y]) {
                        indegree[nx][ny]-- ; 
                        if (indegree[nx][ny] == 0) {
                            Q.push({nx,ny}) ; 
                        }
                    }
                }
            }
            maxlen++ ; 
        }

        return maxlen ; 
    }
};