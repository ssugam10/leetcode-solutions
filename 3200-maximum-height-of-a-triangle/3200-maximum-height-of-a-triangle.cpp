class Solution {
public:
    int f(int fRow, int sRow, int h, int rCt){
        while(fRow >= 0 || sRow >= 0){
            if(h & 1){
                if(sRow - rCt >= 0){
                    sRow -= rCt;
                }
                else break;
            }
            else{
                if(fRow - rCt >= 0){
                    fRow -= rCt;
                }
                else break;
            }
            
            h++;
            rCt++;
        }
        
        return h;
    }
    
    int maxHeightOfTriangle(int red, int blue) {
//         int fRow = red;
//         int sRow = blue;
        
//         int h1 = 0;
//         int rCt = 1;
        
        int mex = max(f(red,blue,0,1),f(blue,red,0,1));
        return mex;
        
        
    }
};