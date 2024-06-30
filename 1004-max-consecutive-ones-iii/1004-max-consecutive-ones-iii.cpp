class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int flips = 0;
        int maxLength = -1;
        while(j<n){
            if(nums[j]==1) j++;
            else{
                if(flips<k){
                    flips++;
                    j++;
                }
                else{   //cannot be flipped, you found another window so return its size
                    maxLength = max(maxLength,j-i);
                    while(nums[i]==1) i++;
                    i++;    //since i is moved front of first zero, no change in count of flips
                    j++;
                }
            }   
        }
        maxLength = max(maxLength,j-i);
        return maxLength;
    }
};