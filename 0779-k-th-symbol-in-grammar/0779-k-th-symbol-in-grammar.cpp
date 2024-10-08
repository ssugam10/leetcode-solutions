class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        if(k%2==0){ //flip answer, k/2
            int prevAns = kthGrammar(n-1,k/2);
            if(prevAns == 0) return 1;
            else return 0;
        }
        else{   //same, k/2+1
            return kthGrammar(n-1,k/2+1);
        }
    }
};