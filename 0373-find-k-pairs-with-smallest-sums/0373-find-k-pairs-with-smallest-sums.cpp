#define pp pair< int, pair<int,int>> 

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<vector<int>> ans;

        int i = 0;  //pointer for nums1
        int j = 0;  //pointer for nums2

        for(i = 0; i<nums1.size(); i++){
            pq.push({nums1[i] +  nums2[j], {i,j}}); //pushed the starting elements of all the arrays(whose start ele is nums1[i])
        }

        i = 0;

        pp curr;
        while(!pq.empty() && k--){
            curr = pq.top();
            pq.pop();
            i = curr.second.first;
            j = curr.second.second;
            ans.push_back({nums1[i],nums2[j]});
            if(j+1 < nums2.size()){
                pq.push({nums1[i]+nums2[j+1], {i,j+1}});
            }
        }

        return ans;

    }
};