class Solution {
public:
    
    int dfs(int node, int parent, int k, vector<vector<int>> &tree){
        
        if(k <= 0)  return k + 1;
        
        int num = 0;
        
        for(auto child : tree[node]){
            if(child == parent) continue;
            
            num += dfs(child, node, k - 1, tree);
        }
        
        return num + 1;
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        
        vector<vector<int>> treeOne, treeTwo;
        vector<int> targetLen;
        
        treeOne.resize(n);
        targetLen.resize(n, 0);
        
        for(auto &edge : edges1){
            treeOne[edge[0]].push_back(edge[1]);
            treeOne[edge[1]].push_back(edge[0]);
        }
        
        for(int i = 0; i < n; i++){
            targetLen[i] = dfs(i, -1, k, treeOne); 
        }
        
        
        treeTwo.resize(m);
        for(auto &edge : edges2){
            treeTwo[edge[0]].push_back(edge[1]);
            treeTwo[edge[1]].push_back(edge[0]);
        }
        
        int mx = 0;
        
        for(int i = 0; i<m; i++){
            mx = max(mx, dfs(i, -1, k - 1, treeTwo));
        }
        
        //cout<<mx<<endl;
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            if(targetLen[i] == 0)   break;
            
            ans.push_back(mx + targetLen[i]);
        }
        
        
        return ans;
    }
};