class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        
        unordered_map<int,int> buckets;  //Stores elements that can be grouped together in the same bucket
        
        for(int i = 0; i<n; i++){
            int bucket = nums[i] / (valueDiff + 1);
            
            if(nums[i] < 0) bucket--;
            
            if(buckets.find(bucket) != buckets.end())   return true;
            
            else{
                buckets[bucket] = nums[i];
                
                if(buckets.find(bucket-1) != buckets.end() && nums[i] - buckets[bucket-1] <= valueDiff)   return true;
                if(buckets.find(bucket+1) != buckets.end() && buckets[bucket + 1] - nums[i] <= valueDiff)   return true;
                
                if(buckets.size() > indexDiff){
                    int key = nums[i - indexDiff] / (valueDiff + 1);  //This element is to be removed since we are using sliding window
                    if(nums[i - indexDiff] < 0) key--;
                    buckets.erase(key);
                }
            }
        }
        
        return false;
    }
};