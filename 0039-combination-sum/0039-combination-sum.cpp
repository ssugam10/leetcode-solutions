class Solution {
public:
    vector<vector<int>> ans;

    void findSum(vector<int>& candidates, vector<int>& numbers, int target, int i){
        if(target == 0){
            ans.push_back(numbers);
            return;
        }

        if(i == candidates.size())  return;

        //take
        if(target >= candidates[i]){
            numbers.push_back(candidates[i]);
            findSum(candidates,numbers,target-candidates[i], i);
            numbers.pop_back();
        }

        //not take
        int k = i + 1;
        // while(k < candidates.size() &&  candidates[i] == candidates[k]){
        //     k++;
        // };
        findSum(candidates,numbers,target,k);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> nums = {};
        ans.clear();
        sort(candidates.begin(),candidates.end());
        findSum(candidates,nums,target,0);
        return ans;
    }
};