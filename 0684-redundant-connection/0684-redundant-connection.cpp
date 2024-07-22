class Solution {
public:

void dfs(int n,vector<vector<int>>&adj,vector<bool>&vis){
    vis[n]=true;
    for(auto i:adj[n]){
        if(!vis[i]){
            vis[i]=true;
        dfs(i,adj,vis);
        }
    }
}

bool connected(vector<vector<int>>&adj,vector<bool>&vis,int n){
    dfs(0,adj,vis);
    
    for(int i = 0; i<n; i++){
        if(!vis[i]) return false;
    }
    
    return true;
    
    // int c=0;
    // for(int i=0;i<n;i++){
    //     if(vis[i]==0){
    //     dfs(i,adj,vis);
    //     c++;
    // }
    // }
    // return c;

}


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
                int n=edges.size();

vector<vector<int>>adj(n);
        vector<int>v;
        for(auto i:edges){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);

        }

        for(int i=edges.size()-1;i>=0;i--){
            int a=edges[i][0]-1;
            int b=edges[i][1]-1;
            auto it=find(adj[a].begin(),adj[a].end(),b);
            adj[a].erase(it);

            auto it1=find(adj[b].begin(),adj[b].end(),a);
            adj[b].erase(it1);

            vector<bool>vis(n,false);

            // for(auto i:adj){
            //     for(auto j:i)
            //     cout<<j<<" ";
            //     cout<<endl;
            // }
            // cout<<endl;
        
            bool ans=connected(adj,vis,n);

            // cout<<ans<<endl;
            if(ans==true ){
                v.push_back(a+1);
                v.push_back(b+1);
                return v;
}
            else{
            adj[a].push_back(b);
            adj[b].push_back(a);
            }
        }
        return v;
        // return {-1,-1};
    }
};