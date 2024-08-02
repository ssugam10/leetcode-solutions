#define pi pair<int,pair<int,int>>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto ele : flights){
            int source = ele[0];
            int dest = ele[1];
            int cost = ele[2];
            
            adj[source].push_back({dest,cost});
        }
        
        vector<int> distances(n,INT_MAX);
        
        distances[src] = 0;
        
        queue<pi> q;
        
        q.push({0,{0,src}});   //{price, {stops,node}}
        
        while(!q.empty()){
            int dist = q.front().first;
            int node = q.front().second.second;
            int stops = q.front().second.first;
            q.pop();   
            
            if(stops > k) continue;
            
            for(auto neigh : adj[node]){
                int adjNode = neigh.first;
                int edgeW = neigh.second;
                
                if(dist + edgeW < distances[adjNode]){
                    distances[adjNode] = dist + edgeW;
                    q.push({dist + edgeW, {stops + 1,adjNode}});
                }
            }
            
        }
        
        return (distances[dst] == INT_MAX) ? -1 : distances[dst];
    }
};