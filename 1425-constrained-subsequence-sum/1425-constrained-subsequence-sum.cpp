class Solution {
public:
    
    int constrainedSubsetSum(vector<int>& nums, int k) {
       int n = nums.size();
        
        vector<int> dp(n);
        
        for(int i = 0; i<n; i++){
            dp[i] = nums[i];
        }
        
        
        priority_queue<pair<int,int>> pq;   //maxHeap
        pq.push({dp[0],0});
        
        int result = dp[0];

        
        for(int i = 1; i<n; i++){
            
            while(i - pq.top().second > k)  pq.pop();
            
            dp[i] = max(dp[i], nums[i] + pq.top().first);
            
            result = max(result,dp[i]);
            
            pq.push({dp[i],i});
        }
        
        
        return result;
        
    }
};