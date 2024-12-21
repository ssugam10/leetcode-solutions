#define ll long long int

class Solution {
public:
    int components;
    int k;
    
    ll f(int node, int parent, vector<vector<int>> &graph, vector<int> &values){
        
        ll sum = 0;
        
        //Traverse to all children
        for(auto &child : graph[node]){
            if(child == parent) continue;
            
            ll childSum = f(child, node, graph, values);
            if(childSum % k == 0)   components++;
            else{
               sum += childSum; 
            }
        }
        
        return sum + values[node];
    }
        
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        
        for(auto &edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        components = 1;
        this->k = k;
        
        f(0,-1,graph,values);
        
        return components;
        
    }
};