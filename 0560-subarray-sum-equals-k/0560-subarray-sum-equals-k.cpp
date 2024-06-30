class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i<n; i++){
            pre[i] = nums[i] + pre[i-1];
        }

        unordered_map<int,int> mp;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(pre[i] == k) count++;    //If subarray starting from 0th index till now is equal to k then consider it

            int rem = pre[i] - k;
            count += mp[rem];    //we are adding frequency of how many subarrays with curr ele are possible
            mp[pre[i]]++;   
        }
        return count;
    }
};