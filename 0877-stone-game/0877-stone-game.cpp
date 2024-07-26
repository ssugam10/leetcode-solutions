class Solution {
public:
    vector<int> piles;
    int dp[505][505];

    int f(int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int pickLeft = piles[i] + min(f(i+2, j), f(i+1, j-1));
        int pickRight = piles[j] + min(f(i+1, j-1), f(i, j-2));
        
        return dp[i][j] = max(pickLeft, pickRight);
    }
    
    bool stoneGame(vector<int>& piles) {
        this->piles = piles;
        memset(dp, -1, sizeof(dp));
        
        int totalSum = accumulate(piles.begin(), piles.end(), 0);
        int ans = f(0, piles.size() - 1);
        
        return ans > totalSum / 2;
    }
};
