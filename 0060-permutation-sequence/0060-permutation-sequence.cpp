class Solution {
public:
    string permutation(string str, int k, string ans){
        int n = str.length();
        if(n==1){
            ans += str;
            return ans;
        }
        int fact = 1;   //holds factorial of n-1
        for(int i = 2; i<=n-1; i++){
            fact *= i;
        }
        int idx = k/fact;   //idx indicates the block number since each 2nd char takes (n-1)! length block
        if(k%fact == 0) idx--;
        char ch = str[idx];
        string left = str.substr(0,idx);
        string right = str.substr(idx+1);
        int q = 1;
        if(k%fact==0) q = fact;
        else q = k%fact;
        return permutation(left+right,q,ans+ch);
    }
    string getPermutation(int n, int k) {
        string original = "";
        for(int i=1;i<=n;i++){
            original += to_string(i);
        }
        return permutation(original,k,"");
    }
};