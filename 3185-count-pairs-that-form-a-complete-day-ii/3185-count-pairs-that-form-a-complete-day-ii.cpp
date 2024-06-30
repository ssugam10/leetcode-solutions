#define ll long long int
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        ll ct = 0;
        map<ll,ll> mp;
        int n = hours.size();
        for(auto ele : hours){
            ll rem = ele % 24;
            if(rem == 0){
                ct += mp[0];
            }
            else{
                ct += mp[24-rem];
            }
            
            mp[rem]++;
        }
        
        return ct;
        
    }
};