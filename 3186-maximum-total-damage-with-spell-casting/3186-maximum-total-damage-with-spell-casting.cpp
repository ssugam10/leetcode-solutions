#define ll long long int
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

class Solution {
public:
    vector<ll> dp;
    int n;

    ll f(int i, vector<pair<ll,ll>>& p) { 
        if(i == n){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        //not take
        ll notTake = f(i+1,p);
        
        //take  
        ll take = p[i].first * p[i].second;

        for(int k = i+1; k<n; k++){
            if(p[k].first > p[i].first + 2){
                take += f(k,p);
                break;
            }
        }

        return dp[i] = max(take,notTake);
    }

    long long maximumTotalDamage(std::vector<int>& power) {
        map<ll,ll> mp;
        for(int i = 0; i<power.size(); i++){
            mp[power[i]]++;
        }

        dp.clear();

        vector<pair<ll,ll>> p;
        
        for(auto it = mp.begin(); it!=mp.end(); it++){
            p.push_back({it->first,it->second});
            //cout<<it->first<<" "<<it->second<<"\n";
        }

        n = p.size();
        dp.resize(n,-1);

        ll ans = f(0,p);
        return ans;
    }
};