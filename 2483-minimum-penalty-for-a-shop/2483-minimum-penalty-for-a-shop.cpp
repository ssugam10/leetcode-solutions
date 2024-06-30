#include <vector>
#include <climits>

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> pre(n+1),suf(n+1);
        pre[0] = 0;
        suf[n] = 0;
        //Assuming we close the shop at nth hour
        //In pre we calculate number of 'N' occuring before the nth hour index
        //In suf we calculate number of 'Y' occuring inluding and after nth hour index
        for(int i = 1; i<=n; i++){
            pre[i] += pre[i-1] + ((customers[i-1]=='N')?1:0);
            suf[n-i] += suf[n-i+1] + ((customers[n-i]=='Y')?1:0);
        }

        //Instead of creating a new penalty array, I have updated changes in prefix array itself
        int minPenalty = INT_MAX;
        for(int i = 0; i<=n; i++){
            pre[i] += suf[i];   
            if(minPenalty > pre[i]) minPenalty = pre[i];
        }
        //pre[i] now indicates the number of penalties if the shop is closed at ith hour

        //Now we finally traveerse pre array and return the first occurrence index of minPenalty
        for(int i = 0; i<=n; i++){
            if(pre[i] == minPenalty) return i;
        }
        return -1;
    }
};