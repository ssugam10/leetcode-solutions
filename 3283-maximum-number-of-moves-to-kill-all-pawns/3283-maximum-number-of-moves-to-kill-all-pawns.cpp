class Solution {
public:
    int n;
    vector<vector<int>> pos;
    
    vector<pair<int, int>> moves = {{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    
    vector<vector<int>> dist;
    
    int match(int row, int col){
        for(int i = 0; i < pos.size(); i++){
            if(row == pos[i][0] && col == pos[i][1])  return i; 
        }
        return -1;
    }
    
    // BFS to find minimum moves to reach from pos[i] to all other pawns
    void bfs(int i){
        int vis[50][50];
        memset(vis,-1,sizeof(vis));
        queue<pair<int, int>> q;
        q.push({pos[i][0], pos[i][1]});
        vis[pos[i][0]][pos[i][1]] = 1;
        
        dist[i][i] = 0; // Distance from the node to itself is 0
        int distance = 1;
        
        while(!q.empty()){
            int size = q.size(); // Store the current size of the queue
            
            for(int k = 0; k < size; k++){  // Iterate over current level nodes
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(auto next : moves){
                    int ro = row + next.first;
                    int co = col + next.second;

                    if(ro >= 0 && ro < 50 && co >= 0 && co < 50 && vis[ro][co] == -1){
                        
                        int check = match(ro,co);
                        
                        if(check != -1){
                            dist[i][check] = distance;
                        }
                        
                        q.push({ro, co});
                        vis[ro][co] = 1;
                    }
                }
            }
            distance++;  // Increase the distance after processing each level
        }
    }
    
    void preCompute(){
        for(int i = 0; i<n; i++){
            bfs(i);
        }
    }
    
    // DP portion starts here
    
    int dp[16][(1 << 16) + 1];
    
    /* No need to consider flag in dp since the parity of number of ones set in the mask will be same for alice's all moves, 
    which will be same for bob and opposite to the parity of alice's, so keeping flag as a part of dp is redundant */
    
    int f(int curr, int mask, bool flag){
        // All pawns have been captured so no more moves!
        if(mask == (1 << n) - 1) return 0;
        
        if(dp[curr][mask] != -1)    return dp[curr][mask];
        
        int ans = flag ? INT_MIN : INT_MAX;  
        
        for(int i = 0; i < n; i++){
            // Unvisited element
            if((mask & (1 << i)) == 0){  
                if(!flag){
                    // Bob tries to minimize
                    ans = min(ans, dist[curr][i] + f(i, mask | (1 << i), true));
                }
                else{
                    // Alice tries to maximize
                    ans = max(ans, dist[curr][i] + f(i, mask | (1 << i), false));
                }
            }
        }
        return dp[curr][mask] = ans;
    }
    
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        positions.push_back({kx, ky});  // Include the knight position
        n = positions.size();    
        pos = positions;

        // Initialize the distance vector after determining 'n'
        dist = vector<vector<int>>(n, vector<int>(n, INT_MAX));

        preCompute();
        
        memset(dp,-1,sizeof(dp));
        
        return f(n - 1, (1 << (n - 1)), true);  // Start with Alice's turn
    }
};
