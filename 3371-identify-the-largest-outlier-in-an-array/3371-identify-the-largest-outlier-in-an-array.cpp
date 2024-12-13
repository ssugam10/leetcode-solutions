class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        map<int,int> freq;
        
        for(auto ele : nums){
            freq[ele]++;
        }
        
        int outlier = -2000;
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        for(auto &ele : nums){
            freq[ele]--;
            
            int rem = sum - ele;
            
            if(rem % 2 == 0){
                if(freq[rem / 2]){
                    outlier = max(ele, outlier);
                }
            }
            
            freq[ele]++;
        }
        
        return outlier;
    }
};