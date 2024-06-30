class Solution {
public:
    bool check(int mid, vector<int>& piles, int h){
        long long hours = 0;
        for(int i = 0; i<piles.size(); i++){    //Each iteration calculates hours spent in finishing a pile
            if(mid >= piles[i]) hours++;
            else{
                if(piles[i]%mid == 0){
                    hours += (long long)(piles[i]/mid);
                }
                else{
                    hours = hours + (long long)((piles[i]/mid) + 1);
                }
            }
        }
        if(hours<=(long long)h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1; //minimum speed is 1
        int hi = -1;    //maximum eating speed is the maximum element of the array in magnitude
        for(int i = 0; i<piles.size() ; i++){
            if(piles[i] > hi) hi = piles[i];
        }
        int minSpeed;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid, piles, h)){
                hi = mid - 1;
                minSpeed = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        return minSpeed;
    }
};