class Solution {
public:
    int n;
    
    int f(int i, int mask, vector<int> &nums){
        
        if(i == n && mask == 0) return 1;
        
        if(i == n)  return 0;
        
        int cnt = 0;
        
        int temp = mask;
        
        //consider nums[i]
        
        for(int j = 0; j<32; j++){
            if((nums[i] & (1 << j) && (mask & (1 << j)))){
                temp ^= (1 << j);
            }
        }
        
        cnt = f(i+1,temp,nums);
        
        //dont consider nums[i]
        cnt += f(i+1,mask,nums);
        
        return cnt;
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        
        int mx = 0;
        for(int i = 0; i<n; i++){
            mx = mx | nums[i];
        }
        
        return f(0,mx,nums);
    }
};