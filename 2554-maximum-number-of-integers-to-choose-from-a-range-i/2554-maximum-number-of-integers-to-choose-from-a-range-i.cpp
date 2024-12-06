class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> ban(banned.begin(),banned.end());
        
        int sum = 0, cnt = 0;
        
        for(int i = 1; i <= n; i++){
            if(ban.find(i) == ban.end()){
                if(sum + i <= maxSum){
                    sum += i;
                    cnt++;
                }
                else    break;
            }
        }
        
        return cnt;
    }
};