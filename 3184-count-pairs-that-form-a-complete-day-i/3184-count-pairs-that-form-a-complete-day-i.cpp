class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        int ct = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                long long int sum = hours[i] + hours[j];
                if(sum % 24 == 0){
                    ct++;
                }
            }
        }
        
        return ct;
    }
};