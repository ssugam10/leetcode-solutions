class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0  ; i<n; i++){
            mp[nums[i]]++;
        }
        
        int ans = 0;
        
        for(auto ele : mp){
            if(ele.second == 2){
                ans ^= ele.first;
            }
        }
        
        return ans;
        
    }
};