class Solution {
public:
    bool find(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        
        if (i < 0 && j>0) { 
            while(j >= 0 && s2[j] == '*') j -= 2;
            // while(s2[j] == '*') j--;
            // if(j == 0)  return true;
        }
        
        if (i < 0 && j < 0)     return true; 
        
        if (i < 0 || j < 0)  return false; 

        if (dp[i][j] != -1) return dp[i][j];

        bool match = false;
        
        if (s2[j] == s1[i] || s2[j] == '.') { 
            match = find(i - 1, j - 1, s1, s2, dp);
        } 
        else if (s2[j] == '*') { 
           int k = j - 1;   //there is always a valid char acc to constraints
            match = match || find(i,k-1,s1,s2,dp);  //consider it zero times
            int it = 0;
            while(i - it >= 0 && (s2[k] == s1[i-it] || s2[k] == '.')) { 
                match = match || find(i - it - 1, k-1, s1, s2, dp);
                it++;
            }
            
        }

        return dp[i][j] = match;
    }
    

    bool isMatch(string s, string b) {
      int n = s.size();


     string B = "";
     int i = 0;
     while (i < b.size()) {
         if (b[i] == '*') {
             if (B.size() > 0 && B.back() == '*') {
                 i++;
                 continue;
             }
         }
         B += b[i];
         i++;
     }
        int m = B.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return find(n - 1, m - 1, s, B, dp);
    }
};