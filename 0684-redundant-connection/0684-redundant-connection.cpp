class Solution {
public:

void dfs(int n,vector<vector<int>>&adj,vector<int>&vis){
    vis[n]=1;
    for(auto i:adj[n]){
        if(vis[i]==0){
            vis[i]=1;
        dfs(i,adj,vis);
        }
    }
}

int connected(vector<vector<int>>&adj,vector<int>&vis,int n){
    int c=0;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
        dfs(i,adj,vis);
        c++;
    }
    }
    return c;

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

            vector<int>vis(n,0);

            // for(auto i:adj){
            //     for(auto j:i)
            //     cout<<j<<" ";
            //     cout<<endl;
            // }
            // cout<<endl;
        
            int ans=connected(adj,vis,n);

            // cout<<ans<<endl;
            if(ans==1 ){
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