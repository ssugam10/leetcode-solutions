class Solution {
public:
    vector<list<int>> adj;
    
    void dfs(int node, vector<bool> &visited){
        visited[node] = true;
        for(auto neigh : adj[node]){
            if(!visited[neigh]){
                dfs(neigh,visited);
            }
        }
    }
    
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        set<int> possibleRoots;
        
        adj.clear();
        adj.resize(n);
        
        vector<int> indegree(n,0);

        int mark = -1;
        for(int i = 0; i<n; i++){
            adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
            indegree[edges[i][1] - 1]++;
            
            if(indegree[edges[i][1] - 1] == 2){
                mark = edges[i][1] - 1;
            }
        }

        if(mark != -1){
            int root = -1;
            for(int i = n-1; i>=0; i--){
                if(indegree[i] == 0){
                    root = i;
                    break;
                }
            }

            for(int i = n-1; i>=0 ; i--){
                int from = edges[i][0] - 1;
                int to = edges[i][1] - 1;
                if(to == mark){
                    auto it = find(adj[from].begin(), adj[from].end(), to);
                    adj[from].erase(it);
                    vector<bool> visited(n,false);
                    dfs(root,visited);

                    bool flag = true;
                    for(int i = 0; i<n; i++){
                        if(!visited[i]){
                            flag = false;
                            break;
                        }
                    }

                    if(flag)    return edges[i];
                    else adj[from].push_back(to);
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            vector<bool> visited(n,false);
            dfs(i,visited);
            
            bool flag = true;
            for(int i = 0; i<n; i++){
                if(!visited[i]){
                    flag = false;
                    break;
                }
            }
            
            if(flag){
                possibleRoots.insert(i);
            }
        }
        
        // for(auto ele : possibleRoots){
        //     cout<<ele<<" ";
        // }
        
        for(int i = n-1; i>=0; i--){
            int probableRoot = edges[i][1] - 1;
            if(possibleRoots.find(probableRoot) != possibleRoots.end()) return edges[i];
        }
        
        return {};
    }
};