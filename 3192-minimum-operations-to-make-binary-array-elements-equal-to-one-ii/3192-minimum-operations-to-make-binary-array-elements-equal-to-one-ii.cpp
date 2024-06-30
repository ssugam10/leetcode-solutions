class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        for(int i = 0; i<n; i++){
            int newBit;
            if(ops % 2 == 0){
                newBit = nums[i];
            }
            else newBit = (nums[i]==1) ? 0 : 1;
            
            if(newBit == 0){
                ops++;
            }
        }
        
        return ops;
    }
};