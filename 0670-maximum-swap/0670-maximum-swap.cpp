class Solution {
public:
    int maximumSwap(int num) {
        string number = to_string(num);
        
        int n = number.size();
        
        int mx = -1, mxIdx = -1, left = -1, right = -1;
        
        for(int i = n - 1; i >= 0; i--){
            
            if(number[i] > mx){
                mx = number[i];
                mxIdx = i;
                continue;
            }
            
            //Set this as the best candidate to be swapped with the max on its right
            if(mx > number[i]){
                left = i;
                right = mxIdx;
            }
        }
        
        if(left == -1)  return num;
        
        swap(number[left],number[right]);
        
        return stoi(number);
    }
};