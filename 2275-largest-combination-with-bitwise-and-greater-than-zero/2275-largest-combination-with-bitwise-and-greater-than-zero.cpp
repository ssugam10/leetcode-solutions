class Solution {
public:
 
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        
        vector<int> bits(32,0);
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j < 32; j++){
                bits[j] += (candidates[i] >> j) & 1;
            }
        }
        
        return *max_element(bits.begin(),bits.end());
    }
};