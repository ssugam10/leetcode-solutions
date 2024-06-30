class Solution {
public:
    bool isPerfectSquare(int n){
        int root = sqrt(n);
        if(root*root == n){
            return true;
        }
        return false;   
    }
    bool judgeSquareSum(int c) {
        int x = 0;
        int y = c;
        while(x<=y){
            if(isPerfectSquare(x) && isPerfectSquare(y)){
                return true;
            }
            else if(!isPerfectSquare(y)){   //y should keep on decreasing, x increasing 
                int root = sqrt(y);
                y = root * root;
                x = c - y;
            }
            else{   //x is not perfect square, we then assign it nearby greater perfect square value
                int root = sqrt(x);
                x = (root + 1)*(root + 1);
                y = c - x;
            }
        }   
        return false;
    }
};