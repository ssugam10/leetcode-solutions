#define pp pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        vector<int> ans;

        unordered_map<int,int> mp;

        int n = nums.size();
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto ele : mp){
            pq.push({ele.second,ele.first});
            if(pq.size() > k)   pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};