class Solution {
public:
    
    set<int> visited;
    vector<set<int>> newGraph;
    
    void dfs(int node, int parent, vector<set<int>> &graph, string &s, map<char,int> &mp){
        
        if(visited.find(node) != visited.end())    return;
        visited.insert(node);
        
        int prev = -1;
        
        if(mp.find(s[node]) != mp.end()){
            prev = mp[s[node]];
            newGraph[prev].insert(node);
        }
        else{
            if(parent != -1)    newGraph[parent].insert(node);
        }
        
        mp[s[node]] = node;
        
        for(auto child : graph[node]){
            dfs(child, node, graph, s, mp);
        }
        
        if(prev == -1)  mp.erase(s[node]);
        else mp[s[node]] = prev;
    }
    
    int traverse(int node, vector<int> &ans, vector<set<int>> &newGraph){
        int sz = 1;
        
        for(auto child : newGraph[node]){
            sz += traverse(child, ans, newGraph);
        }
        
        return ans[node] = sz;
    }
    
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        
        vector<set<int>> graph(n);
        
        for(int i = 1; i<n; i++){
            graph[parent[i]].insert(i);
        }
        
        map<char,int> mp;
        visited.clear();
        
        newGraph.clear();
        newGraph.resize(n);
        
        dfs(0,-1,graph,s,mp);
        
        vector<int> ans(n);
        traverse(0,ans,newGraph);
        
        return ans;
    }
};