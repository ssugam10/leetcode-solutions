#define ll long long int
class Solution {
public:
    int lastStair;
    unordered_map<int,unordered_map<int,unordered_map<int,int>>> dp;
    ll f(ll i, ll jump, bool canGo){

        if(i > lastStair + 1)   return 0;

        if(dp.count(i) && dp[i].count(jump) && dp[i][jump].count(canGo))  return dp[i][jump][canGo];

        ll ways = (i == lastStair);

        if(canGo == true && i>0)    ways += f(i-1,jump,false);

        ways += f(i+pow(2,jump),jump+1,true);

        return dp[i][jump][canGo] = ways;
    }

    int waysToReachStair(int k) {
        lastStair = k;
        return f(1,0,true);
    }
};