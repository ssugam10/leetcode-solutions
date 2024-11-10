class Solution {
public:
    bool greaterThanK(vector<int> &bits, int k){
        int num = 0;
        
        for(int i = 0; i<32; i++){
            if(bits[i] > 0) num |= (1 << i);
        }
        
        return (num >= k);
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> bits(32,0);
        
        int i = 0, j = 0;
        
        int ans = INT_MAX;
        
        while(j < n){
            for(int m = 0; m < 32; m++){
                if(nums[j] & (1 << m))  bits[m]++;
            }
            
            while(i <= j && greaterThanK(bits,k)){
                ans = min(ans, j - i + 1);
                
                for(int m = 0; m < 32; m++){
                    if(nums[i] & (1 << m))  bits[m]--;
                }
                
                i++;
            }
            
            j++;
        }
        
        while(i < n && greaterThanK(bits,k)){
            ans = min(ans, j - i + 1);

            for(int m = 0; m < 32; m++){
                if(nums[i] & (1 << m))  bits[m]--;
            }

            i++;
        }
        
        if(ans == INT_MAX)  return -1;
        
        return ans;
    }
};