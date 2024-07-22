class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        vector<pair<string,int>> vp(n);
        
        for(int i = 0; i<n; i++){
            vp[i] = {names[i],heights[i]};
        }
        
        sort(vp.begin(),vp.end(), [](auto p1, auto p2){
            return p1.second >= p2.second;
        });
        
        for(int i = 0; i<n; i++){
            names[i] = vp[i].first;
        }
        
        return names;
    }
};
