class Solution {
public:
    
    vector<bool> isEven;
    
    void dfs(int node, int parent, bool iseven, vector<vector<int>> &tree, int &even, int &odd){
        
        if(iseven){
            even++;
            isEven[node] = true;
        }
        else odd++;
        
        for(auto child : tree[node]){
            if(child == parent) continue;
            
            dfs(child, node, !iseven, tree, even, odd);
        }
    }
    
    void dfs2(int node, int parent, bool iseven, vector<vector<int>> &tree, int &even, int &odd){
        
        if(iseven){
            even++;
        }
        else odd++;
        
        for(auto &child : tree[node]){
            if(child == parent) continue;
            
            dfs2(child, node, !iseven, tree, even, odd);
        }
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        
        vector<vector<int>> treeOne, treeTwo;
        isEven.resize(n,false);
        treeOne.resize(n);
        treeTwo.resize(m);
        
        for(auto &edge : edges1){
            treeOne[edge[0]].push_back(edge[1]);
            treeOne[edge[1]].push_back(edge[0]);
        }
        
        for(auto &edge : edges2){
            treeTwo[edge[0]].push_back(edge[1]);
            treeTwo[edge[1]].push_back(edge[0]);
        }
        
        int even = 0, odd = 0;
        
        dfs(0,-1,true,treeOne,even,odd);
        
        int evenInTwo = 0, oddInTwo = 0, mx = 0;
        
        dfs2(0,-1,true,treeTwo,evenInTwo,oddInTwo);
        
        mx = max(evenInTwo, oddInTwo);
        
        vector<int> ans;
        
        for(int i = 0; i<n; i++){
            if(isEven[i])   ans.push_back(mx + even);
            else ans.push_back(mx + odd);
        }
        
        return ans;
    }
};