#define ll long long int
class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.rbegin(),maximumHeight.rend());
        
        int n = maximumHeight.size();
        
        ll curr = maximumHeight[0];
        ll sum = maximumHeight[0];
        
        for(int i = 1; i<n; i++){
            if(maximumHeight[i] >= curr)    curr--;
            else curr = maximumHeight[i];
            
            if(curr < n - i)    return -1;
            sum += curr;
        }
        
        return sum;
    }
};