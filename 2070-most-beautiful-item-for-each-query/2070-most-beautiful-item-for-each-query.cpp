class Solution {
public:
    int findIdx(vector<vector<int>> &updated, int val){
        int lo = 0;
        int hi = updated.size() - 1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            
            if(updated[mid][0] <= val){
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        
        return lo;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        
        sort(items.begin(),items.end(), [](auto a, auto b){
            return a[0] < b[0];
        });
        
        // for(auto ele : items){
        //     cout<<ele[0]<<" "<<ele[1]<<endl;
        // }
        
        vector<vector<int>> updated;
        
        updated.push_back(items[0]);
        
        int mx = items[0][1];
        
        for(int i = 1; i<n; i++){
            mx = max(mx, items[i][1]);
            
            if(items[i][0] == updated.back()[0]){
                updated.back()[1] = mx;
            }
            else{
                updated.push_back({items[i][0],mx});
            }
        }
        
        // for(auto ele : updated){
        //     cout<<ele[0]<<" "<<ele[1]<<endl;
        // }
        
        int len = queries.size();
        
        vector<int> ans;
        
        for(int i = 0; i<len ; i++){
            auto it = findIdx(updated, queries[i]);
            
            if(it == 0)    ans.push_back(0);
            
            else {
                ans.push_back(updated[it - 1][1]);
            }
        }
        
        return ans;
    }
};