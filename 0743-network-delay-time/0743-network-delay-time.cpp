#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define pi pair<int,int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        
        pq.push({0, k});
        
        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto neigh : adj[node]) {
                int adjNode = neigh.first;
                int edgeW = neigh.second;
                
                if (dist + edgeW < distance[adjNode]) {
                    distance[adjNode] = dist + edgeW;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }
        
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX) return -1;
            mx = max(mx, distance[i]);
        }
        
        return mx;
    }
};
