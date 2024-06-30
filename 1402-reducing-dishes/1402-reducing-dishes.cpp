class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        if(satisfaction[n-1]<=0) return 0;
        vector<int> suf(n);
        suf[n-1] = satisfaction[n-1];
        int index = 0;
        for(int i = n-2; i>=0; i--){
            suf[i] = suf[i+1] + satisfaction[i];
            if(suf[i] <= 0){
                index = i+1;
                break;
            }
        }
        int coefficient = 0;
        for(int i = index; i<n; i++){
            coefficient += ((i-index+1)*satisfaction[i]);
        }
        return coefficient;
        
    }
};