class Solution {
public:
    vector<bool> visited;
    int n;
    
    bool f(int i, vector<int>& arr){
        if(arr[i] == 0) return true;
        if(visited[i])  return false;
        
        visited[i] = true;
        
        bool ans = false;
        
        if(i + arr[i] < n){
            ans = ans || f(i+arr[i], arr);
        }
        
        if(i - arr[i] >= 0){
            ans = ans || f(i - arr[i], arr);
        }
        
        return ans;
    }
    
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        
        visited.clear();
        visited.resize(n+1,false);
        
        return f(start,arr);
        
    }
};