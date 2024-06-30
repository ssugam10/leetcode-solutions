class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        vector<int> occ;
        for(int i = 0; i<n; i++){
            if(nums[i] == x)    occ.push_back(i);
        }
        
        int mex = occ.size();
        vector<int> ans;
        for(int i = 0; i<queries.size(); i++){
            if(queries[i] > mex)    ans.push_back(-1);
            else ans.push_back(occ[queries[i] - 1]);
        }
        
        return ans;
    }
};