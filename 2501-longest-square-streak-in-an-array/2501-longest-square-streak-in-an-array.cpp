class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        int mx = 1;
        
        vector<int> len(n,1);
        map<int,int> mp;    //maps the number to its index
        
        bool flag = false;
        
        for(int i = 0; i<n; i++){
            int root = sqrt(nums[i]);
            
            if(root * root == nums[i] && mp.find(root) != mp.end()){
                len[i] += len[mp[root]];
                flag = true;
            }
            
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = i;
            }
            
            mx = max(mx, len[i]);
        }
        
        if(!flag)   return -1;
        
        return mx;
    }
};