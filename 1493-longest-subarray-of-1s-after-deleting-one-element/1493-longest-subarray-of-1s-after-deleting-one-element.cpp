class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxLength = 0;
        bool isDeleted = false;
        while(j<n){
            if(nums[j]==1) j++;
            else{
                if(!isDeleted){
                    isDeleted = true;
                    j++;
                }
                else{
                    maxLength = max(maxLength,j-i-1);
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                }
            }
        }
        maxLength = max(maxLength,j-i-1);
        return maxLength;
    }
};