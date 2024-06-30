class Solution {
public:
    void findFactor(int num, unordered_map<int,int>& mp, long long &count){
        if(num==1){
            count += mp[num];
            return;
        }  

        for(int i = 1; i<=sqrt(num); i++){
            if (num%i == 0) 
            { 
                if (num/i == i) 
                    count += mp[i];
    
                else // Otherwise print both 
                    count += (mp[i] + mp[num/i]);
            } 
        }
        
    }
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        long long count = 0;
        unordered_map<int,int> mp;
        
        for(int i = 0; i<m; i++){
            mp[nums2[i]]++;
        }
        
        for(int i = 0; i<n; i++){
            if(nums1[i] % k == 0)   findFactor(nums1[i]/k,mp,count);
        }
        
        return count;
        
    }
};