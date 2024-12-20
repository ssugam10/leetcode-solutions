class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        //Even binary search on the value of k works here but i have applied greedy approach
        
        int n = nums.size();
        
        int k = 0;
        
        int curr = 1, last = 0;
        
        for(int i = 1; i<n; i++){
            if(nums[i] > nums[i - 1]){
                curr++;
                
                if(curr % 2 == 0)   k = max(k,curr / 2);
            }
            else{
                k = max(k, min(curr, last));
                last = curr;
                curr = 1;
            }
        }
        
        k = max(k, min(curr, last));
        
        return k;
    }
};