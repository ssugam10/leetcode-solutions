class Solution {
public:
    int findBouquets(vector<int> &bloomDay, int mid, int k){
        int m = 0;
        int n = bloomDay.size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(bloomDay[i] <= mid){
                cnt++;
            }
            else{
                cnt = 0;
            }
            
            if(cnt >= k){
                m++;
                cnt = 0;
            }
        }
        
        return m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mx = *max_element(bloomDay.begin(),bloomDay.end());
        int lo = 1;
        int hi = mx;
        
        //Binary search on days, for days you need to find how many bouquets can you make with given condition
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int bouquets = findBouquets(bloomDay, mid, k);
            if(bouquets >= m){
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        
        return (lo > mx) ? -1 : lo;
    }
};