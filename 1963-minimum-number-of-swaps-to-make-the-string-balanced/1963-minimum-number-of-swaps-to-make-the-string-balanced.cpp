class Solution {
public:
    int minSwaps(string s) {
        int i = 0;
        int j = s.length();
        
        int open = 0, closed = 0;
        
        int swaps = 0;
        
        while(i < j){
            if(s[i] == '['){
                open++;
            }    
            else    closed++;
            
            if(closed > open){
                while(s[j] == ']')  j--;
                
                swaps++;
                
                closed--;
                open++;
                j--;
            }
            
            i++;
        }
        
        return swaps;
    }
};