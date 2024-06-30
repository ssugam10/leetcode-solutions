#define pp pair<int,pair<int,int>>

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pp , vector<pp>, greater<pp>> pq;
        int n = matrix.size();

        for(int i = 0; i<min(n,k); i++){    //we need to only add few cols if k<n, since we will find kth smallest in start only
            pq.push({matrix[0][i], {0,i}});
        }

        pp ans;
        while(k-- && !pq.empty()){
            ans = pq.top();
            pq.pop();
            int val = ans.first;
            int row = ans.second.first;
            int column = ans.second.second;
            if(row + 1 < matrix.size()){
                pq.push({matrix[row+1][column], {row+1,column}});
            }
        }
        return ans.first;
    }
};