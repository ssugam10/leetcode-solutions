class Solution {
public:
    bool checkForOne(string s, int start, int numOps) {
        int n = s.length();
        
        for(int i = 0; i<n; i++) {
            if(s[i] != '0' + start) numOps--;
            start ^= 1;
        }
        
        return (numOps >= 0);
    }
    
    bool checkOps(string s, int numOps, int sz) {
        if(sz == 1) return checkForOne(s,0,numOps) || checkForOne(s,1,numOps);
        
        int n = s.length();
        char last = s[0];
        int rep = 1;
        int opsNeeded = 0;
        
        for(int i = 1; i<n; i++) {
            if(s[i] == last) {
                rep++;
                if(rep > sz) {
                    opsNeeded++;
                    rep = 0;
                }
            }
            else {
                rep = 1;
                last = s[i];
            }
        }
        
        return (numOps >= opsNeeded);
    }
    
    int minLength(string s, int numOps) {
        int n = s.length();
        
        int lo = 1;
        int hi = n;
        
        int ans = n;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            bool flag = checkOps(s, numOps, mid);
            
            //cout<<mid<<" "<<flag<<endl;
            
            if(flag) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        
        return ans;
    }
};