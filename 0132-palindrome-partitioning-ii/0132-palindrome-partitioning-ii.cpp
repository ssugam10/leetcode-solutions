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
    
    int f(string &s, int i){
        if(i == n)  return 0;
        
        if(dp[i] != -1) return dp[i];
        int minCost = INT_MAX;
        for(int j = i ; j<n; j++){
            if(isPalindrome(s,i,j)){
                int cost = 1 + f(s,j+1);
                minCost = min(minCost,cost);
            }
        }
        
        return dp[i] = minCost;
    }
    
    int minCut(string s) {
        n = s.length();
        dp.assign(n+1,-1);
        return f(s,0) - 1;  //It does an extra partition at the end
    }
};