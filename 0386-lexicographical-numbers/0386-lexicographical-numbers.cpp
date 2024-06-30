class Solution {
public:
    vector<int> ans;

    void f(int i, int n){
        if(i>n) return; 
        if(i<=n && i!=0){
            ans.push_back(i);
        }

        for(int j = (i==0)? 1 : 0 ; j<=9; j++){
            f(10*i+j,n);
        }
    }

    vector<int> lexicalOrder(int n) {
        ans.clear();
        f(0,n);
        return ans;
    }
};