class Solution {
public:
    int n;
    vector<vector<int>> dp; // DP table to memoize results

    int f(int i, int m, vector<int> &piles) {
        if (i == n) return 0; // If all piles are taken
        if (dp[i][m] != -1) return dp[i][m]; // Return memoized result

        int ans = INT_MIN;
        int tot = 0;
        for (int x = 1; x <= 2 * m && i + x <= n; x++) {
            if(i + x - 1 > n)   continue;
            tot += piles[i + x - 1];
            ans = max(ans, tot - f(i + x, max(m, x), piles));
        }

        dp[i][m] = ans;
        return ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<int> pre(n, 0);
        dp.resize(n, vector<int>(n*10, -1)); // Initialize dp table with -1

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += piles[i];
        }
        
        int ans = f(0, 1, piles);

        return (ans + sum) / 2;
    }
};
