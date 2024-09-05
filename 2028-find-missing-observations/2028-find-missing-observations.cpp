class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(),rolls.end(),0);
        int m = rolls.size();
        
        int sumOfNArray = mean * (n + m) - sum;
        
        if(sumOfNArray < n || sumOfNArray > 6 * n) return {};
        
        vector<int> ans(n);
        int temp = n - 1;
        
        for(int i = 0; i < n; i++){
            if(sumOfNArray > 6 * temp){
                ans[i] = (sumOfNArray - 6 * temp);
                sumOfNArray -= (sumOfNArray - 6 * temp);
            }
            else{
                ans[i] = 1;
                sumOfNArray--;
            }
            
            temp--;
        }
        
        return ans;
    }
};