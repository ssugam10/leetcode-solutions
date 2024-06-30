class Solution {
public:
    int mySqrt(int x) {
        int lo = 0;
        int hi = x;
        int mid;
        while(lo <= hi){
            mid = lo + (hi - lo)/2;
            long long m = (long long)mid;
            long long y = (long long)x;
            if((m*m) == y) return mid;
            else if((m*m)>y) hi = mid - 1;
            else lo = mid + 1;
        }
        return hi;
    }
};