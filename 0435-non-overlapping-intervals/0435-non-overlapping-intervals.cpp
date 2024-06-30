bool cmp(vector<int>& i1, vector<int>& i2){
    return i1[1] < i2[1];   //sorting on the basis of end time of intervals
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int lastEndTime = intervals[0][1];
        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][0] < lastEndTime){  //overlapping intervals case
                ans++;
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }
        return ans;
    }
};