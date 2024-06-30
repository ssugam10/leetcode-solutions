bool cmp(vector<int>& a, vector<int>& b){
    return a[1] < b[1];    //end coordinate ke basis pe sort kar raha hu
}

class Solution {    //similar to non-overlapping intervals
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int ans = 0;
        int lastEnd = points[0][1];
        for(int i = 1; i<points.size(); i++){
            if(points[i][0] <= lastEnd ){   //two balloons areas overlap
                ans++;
            }
            else{
                lastEnd = points[i][1];
            }
        }       

        return points.size()-ans;
    }
};