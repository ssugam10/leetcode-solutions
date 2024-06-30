class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<int> ans;
        
        vector<int> dp(n+1,1);
        vector<int> parent(n+1,-1);
        
        int mx = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }   
            
            if(dp[i] > dp[mx]){
                mx = i;    
            }
        }
        
        for(int i = mx; i!=-1; i=parent[i]){
            ans.push_back(nums[i]);
        }
        
        return ans;
        
    }
};