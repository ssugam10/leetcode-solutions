class Solution {
public:
    void generate(int n, int open, int close, string ans, vector<string>& answer){
        if(close==n){
            answer.push_back(ans);
            return;
        }
        if(open<n)  generate(n,open+1,close,ans+'(',answer);
        if(close<open)  generate(n,open,close+1,ans+')',answer);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer={};
        generate(n,0,0,"",answer);
        return answer;
    }
};