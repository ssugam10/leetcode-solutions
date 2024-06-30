class Solution {
public:
    int gd(int n){
        for(int i = 2; i<=sqrt(n); i++){
            if(n%i==0){
                return n/i; //return the biggest factor of n
            }
        }
        return 1;
    }
    bool isPrime(int n){
        if(n==1) return false;
        for(int i = 2; i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }

    int minSteps(int n) {
        int count = 0;
        while(n>1){ //O(log(n))
            if(isPrime(n)){//O(sqrt(n))
                count+=n;
                break;
            }
            int hf = gd(n);//O(sqrt(n))
            count += (n/hf);
            n = hf;
        }
        return count;
    }
};