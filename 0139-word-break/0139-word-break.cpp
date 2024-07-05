class Solution {
public:
    int n;
    vector<int> dp;
    
    bool isPresent(string temp, set<string> &s,string &A){
        if(s.count(temp))   return true;
        return false;
    }

    bool f(int i, string &A, set<string> &s){

        if(i == n)  return true;

        if(dp[i] != -1) return dp[i];

        bool ans = false;
        string temp = "";
        for(int k = i; k<min(n,i+20); k++){
            temp += A[k];
            if(isPresent(temp,s,A)){
                ans |= f(k+1,A,s);
            }
        }

        return dp[i] = ans;
    }

    
    
    bool wordBreak(string A, vector<string>& wordDict) {
        set<string> s;
        for(int i = 0; i<wordDict.size(); i++){
            s.insert(wordDict[i]);
        }
        n = A.size();
        dp.assign(6505,-1);
        return f(0,A,s);
    }
};




