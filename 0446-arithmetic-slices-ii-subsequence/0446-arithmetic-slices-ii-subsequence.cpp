#define ll long long

class Solution {
public:
    vector<unordered_map<ll,ll>> dp;    //dp[i] stores the count of different diff subarrays ending at particular i
    ll fbu(vector<int>& arr){

        ll n = arr.size();
        ll ans = 0;
        for(ll i = 1; i<n; i++){
            for(ll j = i-1; j>=0; j--){
                ll diff = ((ll)arr[i]-(ll)arr[j]);
                dp[i][diff] += dp[j][diff] + 1;
                ans += dp[j][diff];
            }
        }

        return ans;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        dp.clear();
        dp.resize(1005);

        return (int)fbu(nums);
    }
};