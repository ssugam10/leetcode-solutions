class Solution {
public:
    void fillSieve(vector<bool> &sieve){
        for(int i = 2; i<=sqrt(100000); i++){
            if(sieve[i] == 1){
                for(int j = i * 2; j <= 100000; j += i){
                    sieve[j] = 0;
                }
            }
        }    
    }
    
    int nonSpecialCount(int l, int r) {
        //The special numbers are squares of prime numbers
        
        vector<bool> sieve(100001,true);
        sieve[0] = false;
        sieve[1] = false;
        
        fillSieve(sieve);
        
        int left = ceil(sqrt(l));
        int right = sqrt(r);
        
        // cout<<left<<" "<<right<<endl;
        
        int cnt = 0;
        for(int i = left; i<=right; i++){
            if(sieve[i] == 1){
                cnt++;
            }
        }
        
        
        return r - l + 1 - cnt;
    }
};