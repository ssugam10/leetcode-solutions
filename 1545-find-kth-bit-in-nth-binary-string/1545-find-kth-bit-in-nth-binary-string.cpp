class Solution {
public:
    int sz[21];
    
    
    
    char f(int n, int k){
        
        if(n == 1)  return '0';
        
        int mid = sz[n] / 2;
        
        if(k == mid)    return '1';
        
        else if(k > mid)    return (f(n - 1, sz[n - 1] - (k - mid)) == '0') ? '1' : '0';
        
        else return f(n - 1, k);
          
    }
    
    char findKthBit(int n, int k) {
        
        int size = 1;
        sz[1] = size;
        
        for(int i = 2; i <= 20; i++){
            size = 2 * size + 1;
            sz[i] = size;
        }
        
        k--;
        
        return f(n,k);
    }
};