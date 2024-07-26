class Solution {
public:
    int n;
    vector<vector<int>> dp; 

    int f(int i, int m, vector<int> &piles) {
        if (i == n) return 0; // If all piles are taken
        if (dp[i][m] != -1) return dp[i][m]; // Return memoized result

        int ans = INT_MIN;
        int tot = 0;
        for(int k = i ; k<min(i+2*m,n); k++){
            tot += piles[k];
            ans = max(ans, tot - f(k+1,max(m,k - i + 1),piles));
        }

        return dp[i][m] = ans;
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
