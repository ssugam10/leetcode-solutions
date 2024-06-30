class Solution {
public:
    void fillSieve(vector<bool>& sieve){
        int n = sieve.size() - 1;
        for(int i = 2; i<=sqrt(n); i++){
            if(sieve[i]==1) {   //1 means number is prime
                for(int j = i*2; j<=n; j+=i){
                    sieve[j] = 0;
                }
            }
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        int maximum = -1;
        for(int i = 0; i<n; i++){
            maximum = max(maximum,nums[i]);
        }
        vector<bool> sieve(maximum+1,1);
        if(maximum+1>0) sieve[0]=0;
        if(maximum+1>1) sieve[1]=0;
        fillSieve(sieve);
        vector<int> possiblePrimes;
        for(int i = 2; i<=maximum; i++){
            if(sieve[i]){
                possiblePrimes.push_back(i);
            }
        }

        int counter = 0;
        for(int i = 0; i<possiblePrimes.size(); i++){
            int iterator = 0;
            while(iterator<n){
                if(nums[iterator++]%possiblePrimes[i]==0){
                    counter++;
                    break;
                }
            }
        }
        return counter;
    }
};