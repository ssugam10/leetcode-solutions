class Solution {
public:
    
    int check(int node, int parent, int target, vector<vector<int>> &graph, vector<int> &nums, int &comp){
        
        int sum = nums[node];
        
        for(auto &child : graph[node]){
            if(child == parent)     continue;
            
            int childSum = check(child, node, target, graph, nums, comp);
            
            sum += childSum;
        }
        
        if(sum % target == 0)   comp++;
        
        return sum;
    }
    
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        
        vector<vector<int>> graph(n);
        
        for(auto &edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        
        int mx = *max_element(nums.begin(),nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        set<int> factors;
        
        //cout<<sum<<" "<<mx<<endl;
        
        for(int i = 1; i * i <= sum; i++){
            if(sum % i == 0){
                if(i >= mx) factors.insert(i);
                
                if(sum / i >= mx)   factors.insert(sum / i);
            }
        }
        
        int components = 1;
        
        int comp = 0;
        
        for(auto &possibleSum : factors){
            check(0,-1,possibleSum,graph,nums,comp);
            
            if(comp * possibleSum != sum)   comp = 1;
            
            components = max(components, comp);
            
            //cout<<possibleSum<<" "<<comp<<endl;
            
            comp = 0;
            
        }
        
        return components - 1;
    }
};