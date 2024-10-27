class Solution {
public:
    int dp[205][205];    //dp[i][j] -> max score if I am present in city i on day j
    
    int n, k;
    vector<vector<int>> stayScore, travelScore;
        
    int f(int i, int j){
        
        if(j == k)  return 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int ans = 0;
        
        ans = stayScore[j][i] + f(i,j+1);  //stay in current city
        
        for(int k = 0; k<n; k++){
            ans = max(ans, travelScore[i][k] + f(k, j+1));  //travel to some other city
        }
        
        return dp[i][j] = ans;
    }
        
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        this->n = n;
        this->k = k;
        this->stayScore = stayScore;
        this->travelScore = travelScore;
        
        int mx = 0;
        
        memset(dp,-1,sizeof(dp));
        
        for(int i = 0; i<n; i++){
            mx = max(mx, f(i,0));
        }
        
        return mx;
    }
};