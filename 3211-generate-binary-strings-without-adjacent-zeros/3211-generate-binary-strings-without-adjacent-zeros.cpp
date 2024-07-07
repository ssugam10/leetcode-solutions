class Solution {
public:
    vector<string> ans;
    void f(int n, string s){
        if(n == 0){
            ans.push_back(s);
            return;
        }
        else if(n == 1){
            ans.push_back(s + "1");
            if(s[s.length() - 1] == '1'){
                ans.push_back(s + "0");
            }
            return;
        }
   
        else if(n < 0)   return;

        f(n-1,s+"1");
        f(n-2,s+"01");
    }

    vector<string> validStrings(int n) {
        if(n == 1)  return {"0","1"};
        ans.clear();
        f(n,"");
        return ans;
    }
};