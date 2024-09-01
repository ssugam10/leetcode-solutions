class Solution {
public:
    int distance(vector<int>& coordinates) {
        return abs(coordinates[0]) + abs(coordinates[1]);
    }
    
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n = queries.size();
        vector<int> ans;
        ans.reserve(n); 

        priority_queue<int> pq; // Max-heap

        if (n < k) {
            ans.resize(n, -1);
            return ans;
        }
        
        for (int i = 0; i < n; i++) {
            int dist = distance(queries[i]);
            
            if (i < k) {
                pq.push(dist);
            } else {
                if (dist < pq.top()) {
                    pq.pop();
                    pq.push(dist);
                }
            }
            
            if (i < k - 1) {
                ans.push_back(-1);
            } else {
                ans.push_back(pq.top());
            }
        }

        return ans;
    }
};
