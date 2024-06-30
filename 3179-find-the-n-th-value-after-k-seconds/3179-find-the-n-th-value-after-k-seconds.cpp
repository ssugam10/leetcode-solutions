#define mod 1000000007
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<long long> pre(n,1);
        while(k--){
            for(int i = 1; i<n; i++){
            pre[i] = (pre[i-1]%mod + pre[i]%mod)%mod; 
            }    
        }
        
        return pre[n-1];
        
    }
};