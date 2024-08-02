#define pi pair<int,pair<int,int>>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
        effort[0][0] = 0;
        
        pq.push({0,{0,0}});
        
        vector<pair<int,int>> delta = {{1,0}, {-1,0}, {0,1},{0,-1}};
        
        while(!pq.empty()){
            int diff = pq.top().first;
            int ro = pq.top().second.first;
            int co = pq.top().second.second;
            pq.pop();
            
            if(ro == n - 1 & co == m - 1)   return diff;
            
            for(int i = 0; i<4; i++){
                int row = ro + delta[i].first;
                int col = co + delta[i].second;
                
                if(row >=0 && row < n && col >= 0 && col < m){
                    int currEffort = max(diff, abs(heights[row][col] - heights[ro][co]));
                    
                    if(currEffort < effort[row][col]){
                        effort[row][col] = currEffort;
                        pq.push({currEffort,{row,col}});
                    }
                }
            }
        }
        
        return 0;
    }
};