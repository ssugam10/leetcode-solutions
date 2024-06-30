#define pip pair<int,pair<int,int>>
class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<pip,vector<pip>,greater<pip>> pq;
        int mex = INT_MIN;
        for(int i = 0; i<n; i++){
            pq.push({nums[i][0],{i,0}});
            mex = max(mex,nums[i][0]);
        }

        int Fstart = -1000000;
        int Fend = 1000000;
        int start = -1;
        int end = -1;

        while(true){
            start = pq.top().first;
            end = mex;
            if(Fend - Fstart > end - start){
                Fstart = start;
                Fend = end;
            }
            else if(Fend - Fstart == end - start && start < Fstart){
                Fstart = start;
                Fend = end;
            }

            auto curr = pq.top();
            int i = curr.second.first;
            int j = curr.second.second;
            pq.pop();
            if(j + 1 < nums[i].size()){
                pq.push({nums[i][j+1],{i,j+1}});
                mex = max(mex,nums[i][j+1]);
            }
            else break;
        }

        return {Fstart,Fend};
    }
};