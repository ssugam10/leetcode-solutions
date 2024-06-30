class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool parity = (nums[0]%2==0)? 1 : 0; 
        for(int i = 1; i<nums.size(); i++){
            bool currParity = (nums[i]%2==0)? 1 : 0;
            if(currParity == parity){
                return false;
            }
            else{
                parity = currParity;
            }
        }
        
        return true;
    }
};