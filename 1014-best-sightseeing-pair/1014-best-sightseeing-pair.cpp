class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        
        int mx = 0;
        pair<int,int> last = {values[n - 1], n - 1};
        
        for(int i = n - 2; i>=0; i--){
            mx = max(mx, values[i] + last.first + (i - last.second));
            
            if(values[i] + (last.second - i) >= last.first){
                last = {values[i], i};
            }
        }
        
        return mx;
    }
};