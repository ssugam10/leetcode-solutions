class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number = 0;
        int n = nums.size();
        
        
        for(int i = 31; i>=0; i--){
            int set = 0;
            for(int j = 0; j<n; j++){
                if((nums[j]>>i) & 1)    set++;
            }
            
            if(set % 3 != 0){
                number |= (1 << i);
            }
        }
        
        return number;
    }
};