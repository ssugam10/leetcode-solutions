#define ll long long int
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        
        ll black = 0;
        ll swaps = 0;
        
        for(int i = 0; i<n; i++){
            if(s[i] == '1') black++;
            else{
                swaps += (black);
            }
        }
        
        return swaps;
    }
};