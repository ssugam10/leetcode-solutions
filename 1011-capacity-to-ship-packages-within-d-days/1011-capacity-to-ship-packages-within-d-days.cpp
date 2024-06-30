class Solution {
public:
    bool check(int mid, vector<int>& weights, int days){
        int day = 1;    //taken 1 since the last day is not added 
        int temp = mid;
        for(int i = 0 ; i<weights.size() ; i++){
            if(temp - weights[i] >= 0){
                temp -= weights[i];
            }
            else{
                day++;
                temp = mid - weights[i];
            }
            if(day > days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = -1;    //Will be the maximum element from the array
        int hi = 0;     //Will be the sum of elements from the array
        for(int i = 0 ; i<weights.size() ; i++){
            if(weights[i] > lo) lo = weights[i];
            hi += weights[i];
        }

        int answer;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid, weights, days)){  //possible hai toh uske aage ofc possible hai
                hi = mid - 1;
                answer = mid;
            }
            else{   //nahi hai toh uske piche bhi nahi hai
                lo = mid + 1;
            }
        }
        return answer;
    }
};