class Solution {
public:
    string str1;
    string str2;
    int dp[501][501];
    
    // int f(int i, int j){
    //     if(i == -1 && j == -1)  return 0;
    //     if(i == -1) return j + 1;
    //     if(j == -1) return i + 1;

    //     if(dp[i][j] != -1)  return dp[i][j];

    //     if(str1[i] == str2[j]){
    //         return dp[i][j] = f(i-1,j-1);
    //     }

    //     return dp[i][j] = 1 + min({f(i,j-1) , f(i-1,j), f(i-1,j-1)});
    // }

    int fbu(){
        int n = str1.size();
        int m = str2.size();
        //memset(dp, -1 , sizeof dp);
        dp[0][0] = 0;
        for(int i = 1; i<=n; i++){
            dp[i][0] = i;
        }
        for(int i = 1 ; i<=m ; i++){
            dp[0][i] = i;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }

                else{
                    dp[i][j] = 1 + min({dp[i][j-1] , dp[i-1][j], dp[i-1][j-1]});
                }
                
            }
        }

        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        str1 = word1;
        str2 = word2;

        

        return fbu();
    }
};