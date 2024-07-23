#define ll long long int
class Solution {
public:
    string s;
    ll t;
    int n;
    vector<string> ans;
    
    void f(int i, string possible, ll tillNow, ll prevNum){
        
        if(i == n){
            if(tillNow == t){
                ans.push_back(possible);
            }
            return;
        }
        
        ll num = 0;
        string number = "";
        
        for(int j = i; j<n; j++){
            if(j > i && s[i] == '0')    break;  //Leading zeros wale nums consider mat karna
            num = num * 10 + (s[j] - '0');
            number += s[j];
            if(i == 0){
                f(j+1, number, num, num);
            }
            else{
                f(j+1, possible + "+" + number, tillNow + num, num);
                f(j+1, possible + "-" + number, tillNow - num, -num);
                f(j+1, possible + "*" + number, tillNow - prevNum + prevNum * num, prevNum * num);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        s = num;
        t = target;
        n = s.size();
        ans.clear();
        f(0,"",0,0);
        return ans;
    }
};