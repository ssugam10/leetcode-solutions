class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        
        vector<int> ans;
        
        int xorValue = 0;
        
        for(int i = 0; i<n; i++){
            xorValue ^= nums[i];
        }
        
        int k = 0;
        
        for(int i = n - 1; i >= 0; i--){
            
            for(int j = 0; j < maximumBit; j++){
                if(((1 << j) & xorValue) == 0){
                    k |= (1 << j);
                }
            }
            
            ans.push_back(k);
            k = 0;
            
            xorValue ^= nums[i];
        }
        
        return ans;
    }
};