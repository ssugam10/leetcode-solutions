class Solution {
public:
    unordered_set<int> visited;
    vector<int> color;

    int switchColor(int i){
        return (i == 0)? 1 : 0;
    }

    bool check(int src, vector<vector<int>>& graph){
        queue<int> q;
        q.push(src);
        color[src] = 0;
        visited.insert(src);
        while(!q.empty()){
            int curr = q.front();
            int currColor = color[curr];
            q.pop();

            for(auto neigh : graph[curr]){
                if(color[neigh] == -1){
                    color[neigh] = switchColor(currColor);
                    visited.insert(neigh);
                    q.push(neigh);
                }

                else{
                    if(color[neigh] == currColor){
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();   //number of nodes
        color.clear();
        color.resize(n,-1);

        for(int i= 0; i<n; i++){
            if(!visited.count(i)){
                if(!check(i,graph)) return false;
            }
        }

        return true;
    }
};