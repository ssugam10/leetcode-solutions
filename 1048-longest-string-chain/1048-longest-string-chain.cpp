class Solution {
public:
    
    bool isPredecessor(string &s1, string &s2) {
        if(s1.size() != s2.size() + 1) return false;
    
        int first = 0;
        int second = 0;

        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first ++;
                second ++;
            }
            else first ++;
        }
        if(first == s1.size() && second == s2.size()) return true;
        else return false;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
        // Custom comparator to sort strings by their length
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        
        // for(int i = 0; i < n; i++) {
        //     cout << words[i] << endl;
        // }
        
        vector<int> dp(n + 1, 1);  // dp[i] stores length of longest word chain ending at i
        int mx = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(isPredecessor(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            mx = max(mx, dp[i]);
        }
        
        return mx;
    }
};
