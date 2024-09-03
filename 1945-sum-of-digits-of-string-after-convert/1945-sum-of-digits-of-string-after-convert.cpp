class Solution {
public:
    int addNum(string num){
        int n = num.length();
        int val = 0;
        for(int i = 0; i<num.length(); i++){
            val += (num[i] - '0');
        }

        return val;
    }

    int getLucky(string s, int k) {
        string num = "";
        int n = s.length();
        
        for(int i = 0; i<n; i++){
            num += to_string(s[i] - 'a' + 1);
        }

        int ans;
        while(k--){
            ans = addNum(num);
            cout<<ans<<endl;
            num = to_string(ans);
        }
        
        return ans;
    }
};