#define pp pair<int,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pp> pq;  //maxHeap needed

        for(int i = 0; i<points.size(); i++){
            int dist = pow(points[i][0],2) + pow(points[i][1],2);
            pq.push({dist,{points[i][0],points[i][1]}});
            if(pq.size() > k)   pq.pop();
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};