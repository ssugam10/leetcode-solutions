class Solution {
public:
    
    vector<bool> visited;
    
    void dfs(int node, vector<list<int>> &adj){
        visited[node] = true;
        
        for(auto neigh : adj[node]){
            
            if(visited[neigh])  continue;
            
            dfs(neigh,adj);
        }
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<list<int>> adj(n,list<int>());
        vector<int> indegree(n,0);
        
        for(int i = 0; i<invocations.size(); i++){
            indegree[invocations[i][1]]++;
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        
        
        visited.assign(n,false);
        
        dfs(k,adj);
        
        vector<int> sus;
        for(int i = 0; i<n; i++){
            if(visited[i])  sus.push_back(i);
        }
        
        
        for(int i = 0; i<sus.size(); i++){
            for(auto neigh : adj[sus[i]]){
                indegree[neigh]--;
            }
        }
        
        bool flag = true;   //removing all the sus methods
        
        for(int i = 0; i<sus.size(); i++){
            if(indegree[sus[i]] > 0){
                flag = false;
                break;
            }
        }
        
        
        vector<int> ans;
        
        for(int i = 0; i<n; i++){
            if(!visited[i] || !flag)    ans.push_back(i);
        }
        
        return ans;
    }
};