#define ll long long int
#define mod 1000000007
class Solution {
public:
    ll f(ll x, ll y){
        if(y == 0)  return 1;
        ll ans = f(x,y/2);
        ans %= mod;
        if(y & 1){
            return (x * ans * ans) % mod;
        }
        else{
            return (ans * ans) % mod;
        }
    }

    int countGoodNumbers(long long n) {
        ll even = (n+1)/2;
        ll odd = n/2;

        ll evenAns = f(5,even) % mod;
        ll oddAns = f(4,odd) % mod;

        return (int)((evenAns * oddAns) % mod);
    }
};