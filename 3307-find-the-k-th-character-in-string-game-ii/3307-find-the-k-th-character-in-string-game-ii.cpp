class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        
        int n = operations.size();
        
        k--;
        
        //For each set bit in k, we need to consider which operation was applied
        
        int ops = 0;
        
        for(int i = 0; i < min(n,60); i++){
            if((k >> i) & 1){
                ops += (operations[i] == 1);
            }
        }
        
        return 'a' + ops % 26;
    }
};