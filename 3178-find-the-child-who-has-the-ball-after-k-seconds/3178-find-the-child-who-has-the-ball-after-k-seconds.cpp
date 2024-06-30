class Solution {
public:
    int numberOfChild(int n, int k) {
        bool front = true;
        int i = 0;
        while(k--){
            if(front){
                i++;
            }
            if(!front){
                i--;
            }
            if(i == n-1)    front = false;
            if(i == 0)  front = true;
        }
        return i;
    }
};