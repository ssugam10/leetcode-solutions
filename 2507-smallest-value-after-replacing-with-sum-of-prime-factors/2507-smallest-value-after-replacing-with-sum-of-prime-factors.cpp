class Solution {
public:
    bool isPrime(int n){
        if(n==1) return false;
        for(int i = 2; i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }

    int smallestValue(int n) {
        if(isPrime(n))   return n;
        int sum = 0;
        int k = n;  //dummy variable since we cant modify n
        for(int i = 1; i<sqrt(n); i++){
            if(n%i==0 ){ //i is a factor of n
                if(isPrime(i)){ // i is a prime factor of n
                    while(k%i==0 && k!=1){
                        sum+=i;
                        k /= i;
                    }
                }
                int num = n/i;  // for sure num is a factor of n
                if(isPrime(num)){   // num is a prime factor of n
                    while(k%num==0 && k!=1){
                        sum+=num;
                        k /= num;
                    }
                }
            }   
        }
        if(sqrt(n)==(int)sqrt(n) && isPrime(sqrt(n))){
            sum += (sqrt(n)*2);
        }
        if(sum==n) return n;
        return smallestValue(sum);
    }
};