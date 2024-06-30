class Solution {
public:
    bool isPrime(int n){
        if(n==1) return false;
        for(int i = 2; i<=sqrt(n); i++){
            if(n%i==0)  return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int maxPrime = 0;
        for(int i = 0; i<n; i++){
            int key1 = nums[i][i];
            int key2 = nums[i][n-i-1];
            if(key1 > maxPrime && isPrime(key1)) maxPrime = key1;
            if( key2!=key1 && key2>maxPrime && isPrime(key2)) maxPrime = key2;   
        }
        return maxPrime;
    }
};