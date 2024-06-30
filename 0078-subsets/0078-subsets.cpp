class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans = {};
        vector<vector<int>> answer = {};
        createSubset(nums,ans,0,answer);
        return answer;
    }

    void createSubset(vector<int>& nums, vector<int> ans, int idx, vector<vector<int>>& answer){
        if(idx==nums.size()){
            answer.push_back(ans);
            return;
        }
        createSubset(nums,ans,idx+1,answer);
        ans.push_back(nums[idx]);
        createSubset(nums,ans,idx+1,answer);
        
    }
};