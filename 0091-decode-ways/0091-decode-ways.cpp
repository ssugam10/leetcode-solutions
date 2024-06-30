#define ll long long

class Solution {
public:
    vector<ll> dp;

    ll fbu(string &str)
    {
        dp.clear();
        dp.resize(5005, 0);

        if(str[0] != '0')   dp[0] = 1;  
        // else return 0;  //If string contains leading 0's it gives no valid decoding

        if (str.size() > 1)
        {
            if (str[1] != '0')
                dp[1] += dp[0]; 

            if (str[0] - '0' > 0 && (str[0] - '0') * 10 + (str[1] - '0') <= 26)
            {
                dp[1]++;
            }
        }

        for (int i = 2; i < str.size(); i++)
        {
            ll ans = 0;

            if (str[i] - '0' > 0)
            {
                ans += dp[i-1];
            }

            if (str[i - 1] - '0' > 0 && (str[i - 1] - '0') * 10 + (str[i] - '0') <= 26)
            {
                ans += dp[i-2];
            }

            dp[i] = ans;
        }

        return dp[str.size() - 1];
    }


    int numDecodings(string s) {
        dp.clear();
        dp.resize(105,-1);
        return fbu(s);
    }
};