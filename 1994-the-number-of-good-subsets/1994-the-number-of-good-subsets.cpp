#define ll long long int
class Solution {
public:
    int dp[35][1500];
    ll mod = 1000000007;
    
    ll f(int curr, int mask, vector<int> &elig, map<int,int>& numsPrimeMask, vector<int> &v, map<int,int> &freq){
        
        if(curr >= elig.size()){
            ll tot = 1;
            for(auto el : v){
                tot = (tot % mod) * (freq[el] % mod) % mod;
            }
            return tot;
        }
        
        //if(dp[curr][mask] != -1)    return dp[curr][mask] % mod;
        
        ll ans = f(curr + 1, mask, elig, numsPrimeMask, v, freq);
        
        if((numsPrimeMask[elig[curr]] & mask) == 0){
            v.push_back(elig[curr]);
            ans = (ans % mod + f(curr + 1, mask | numsPrimeMask[elig[curr]], elig, numsPrimeMask, v, freq) % mod) % mod;
            v.pop_back();
        }
        
        // return dp[curr][mask] = ans % mod;
        return ans;
    }
    
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
        int sz = primes.size();
        
        map<int,int> primeIndex;
        for(int i = 0; i<sz; i++){
            primeIndex[primes[i]] = sz - i - 1;     // 2 -> 1000000000
        }
        
        
        map<int,int> numsPrimeMask;
        
        int ones = 0;
        
        set<int> eligible;
        map<int,int> freq;
        
        for(auto el : nums){
            if(el == 1){
                ones++;
                continue;
            }
            
            bool take = true;
            int primeMask = 0;
            int curr = el;
            
            for(int j = 2; j*j <= el; j++){
                int cnt = 0;
                while(curr % j == 0){
                    curr /= j;
                    cnt++;
                }
                if(cnt > 0 && cnt != 1){
                    take = false;
                    //break;
                }
                else if(cnt == 1){
                    primeMask |= (1 << primeIndex[j]);
                }
            }
            
            if(curr != 1){
                primeMask |= (1 << primeIndex[curr]);
            }
            
            if(take){
                eligible.insert(el);
                freq[el]++;
                numsPrimeMask[el] = primeMask;
            }
        }
        
        vector<int> v;
        
        vector<int> unique(eligible.begin(),eligible.end());
        
        memset(dp,-1,sizeof(dp));
        
        ll ans = f(0,0,unique,numsPrimeMask,v,freq);
        ans = (ans - 1 + mod) % mod;    //empty subset 
        
        ll ones_ans = 1;
        for(int i = 1; i<=ones; i++){
            ones_ans = ((ones_ans % mod) * (2 % mod)) % mod;
        }
        
        //Handling ones
        ans = (ans % mod + (((ones_ans - 1 + mod) % mod) * (ans % mod)) % mod) % mod;
        
        return ans;
    }
};