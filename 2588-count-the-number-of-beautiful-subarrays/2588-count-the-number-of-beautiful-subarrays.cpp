#define ll long long int

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        int mask = 0;
        
        map<int,int> mp;
        
        mp[mask]++;
        
        ll ans = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j < 20; j++){
                if((1 << j) & nums[i]){
                    mask ^= (1 << j);
                }
            }
            
            ans += (mp[mask]++);
        }
        
        return ans;
    }
};