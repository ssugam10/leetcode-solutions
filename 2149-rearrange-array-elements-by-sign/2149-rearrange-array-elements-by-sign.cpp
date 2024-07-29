class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = -1; //first negative index
        int j = -1; //first positive index
        
        int n = nums.size();
        
        int idx = 0;
        while(true){
            if(nums[idx] < 0 && i == -1){
                i = idx;
            }
            else if(nums[idx] > 0 && j == -1){
                j = idx;
            }
            
            if(i != -1 && j != -1)  break;
            idx++;
        }
        
        vector<int> ans;
        bool flag = true;   //positive is required currently
        while(j < n){
             if(flag){
                 ans.push_back(nums[j]);
                 j++;
                 while(j < n && nums[j] < 0)    j++;
             }
             else{
                 ans.push_back(nums[i]);
                 i++;
                 while(i < n && nums[i] > 0)    i++;    
             }
            
            flag = !flag;
        }
        
        ans.push_back(nums[i]);
        
        
        return ans;
    }
};