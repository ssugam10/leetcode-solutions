class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int mx = *max_element(nums.begin(),nums.end());
        int len = 0;
        
        for(int i = 0; i<n; i++){
            if(nums[i] == mx){
                int ct = 0;
                while(i < n && mx == nums[i]){
                    ct++;
                    i++;
                }
                
                len = max(len,ct);
            }
        }
        
        return len;
    }
};