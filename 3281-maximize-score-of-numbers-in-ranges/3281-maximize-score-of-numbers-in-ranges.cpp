#define ll long long int

class Solution {
public:
    bool check(vector<int> &start, ll gap, ll d){ //checking whether a particular gap can be made or not
        ll last = start[0];
        int n = start.size();
        
        for(int i = 1; i<n; i++){
            ll next = max(last + gap, (ll)start[i]);
            if(next <= d + start[i] && next - last >= gap){
                last = next;
            }
            else return false;
        }
        
        return true;
    }
    
    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        
        sort(start.begin(),start.end());
        
        ll hi = start[n - 1] - start[0] + d;
        ll lo = 1;
        
        while(lo <= hi){
            ll mid = (lo + hi) / 2;
            bool ans = check(start, mid, d);
            
            if(ans){
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        
        return hi;
    }
};