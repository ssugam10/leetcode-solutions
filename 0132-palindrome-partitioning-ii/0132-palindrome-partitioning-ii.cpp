class Solution {
public:
    vector<int> dp;
    int n;
    
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j])    return false;
            i++;
            j--;
        }
        return true;
    }
    
//     int f(string &s, int i){
//         if(i == n)  return 0;
        
//         if(dp[i] != -1) return dp[i];
//         int minCost = INT_MAX;
//         for(int j = i ; j<n; j++){
//             if(isPalindrome(s,i,j)){
//                 int cost = 1 + f(s,j+1);
//                 minCost = min(minCost,cost);
//             }
//         }
        
//         return dp[i] = minCost;
//     }
    
    int fbu(string &s){
        dp.clear();
        dp.resize(n+1,INT_MAX);
        dp[n] = 0;
        
        for(int i = n-1; i>=0 ; i--){
            for(int j = i; j<n; j++){
                if(isPalindrome(s,i,j)){
                    int cost = 1 + dp[j+1];
                    dp[i] = min(dp[i],cost);
                }
            }
        }
        
        return dp[0] - 1;
    }
    
    int minCut(string s) {
        n = s.length();
        // dp.assign(n+1,-1);
        // return f(s,0) - 1;  //It does an extra partition at the end
        
        return fbu(s);
    }
};