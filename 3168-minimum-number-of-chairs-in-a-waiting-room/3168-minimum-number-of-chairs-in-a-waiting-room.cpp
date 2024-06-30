class Solution {
public:
    int minimumChairs(string s) {
        int n = s.size();
        int ct = 0;
        int mex = 0;
        for(int i =0; i<n; i++){
            if(s[i] == 'E') ct++;
            else ct--;
            if(ct > mex)    mex = ct;
        }
        
        return mex;
    }
};