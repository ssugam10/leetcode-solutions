#define ll long long int

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        // for(auto ele : nums){
        //     cout<<ele<<" ";
        // }
        // cout<<endl;
        
        ll pairs = 0;
        
        for(int i = 1; i<n; i++){
            
            // nums[i] + nums[x] >= lower (I want to find such x)
            int x = lower_bound(nums.begin(), nums.end(), lower - nums[i]) - nums.begin();
            
            // nums[i] + nums[y] <= upper (I want to find such y)
            int y = upper_bound(nums.begin() , nums.end(), upper - nums[i]) - nums.begin();
            
            y--;
            
            y = min(y, i - 1);
            
            //cout<<x<<" "<<y<<endl;
            
            if(x > y)  continue;
            
            pairs += (y - x + 1);
        }
        
        return pairs;
        
    }
};