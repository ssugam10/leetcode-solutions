class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b){
            if(a[0] == b[0])    return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int n = envelopes.size();
        
        vector<int> lis;
        
        for(int i = 0; i<n; i++){
            auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
            if(it == lis.end()){
                lis.push_back(envelopes[i][1]);
            }
            else{
                *it = envelopes[i][1];
            }
        }
        
        return lis.size();
    }
};