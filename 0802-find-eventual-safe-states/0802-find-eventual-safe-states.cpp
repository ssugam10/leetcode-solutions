class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();   //number of vertices
        vector<vector<int>> adj(n);

        for(int i = 0; i<n; i++){
            for(auto neigh : graph[i]){
                adj[neigh].push_back(i);
            }
        }

        vector<int> indegree(n,0);
        for(int i = 0; i<n; i++){
            for(auto neigh : adj[i]){
                indegree[neigh]++;
            }
        }

        vector<int> safe;
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
                safe.push_back(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto neigh : adj[curr]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                    safe.push_back(neigh);
                }
            }
        }

        sort(safe.begin(),safe.end());
        return safe;
    }
};