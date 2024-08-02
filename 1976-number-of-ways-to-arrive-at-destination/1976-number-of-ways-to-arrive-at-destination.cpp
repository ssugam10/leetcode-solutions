#include <vector>
#include <queue>
#include <climits>

#define pi pair<long long, int>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto &ele : roads){
            adj[ele[0]].push_back({ele[1], ele[2]});
            adj[ele[1]].push_back({ele[0], ele[2]});
        }
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        pq.push({0, 0}); // {dist, node}
        
        vector<long long> distances(n, LLONG_MAX), ways(n, 0);
        distances[0] = 0;
        ways[0] = 1;
        
        int mod = (int)(1e9 + 7);
        
        while(!pq.empty()){
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;
                
                if(dist + edgeW < distances[adjNode]){
                    distances[adjNode] = dist + edgeW;
                    ways[adjNode] = ways[node];
                    pq.push({distances[adjNode], adjNode});
                } else if(dist + edgeW == distances[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        
        return (int)(ways[n - 1] % mod);
    }
};
