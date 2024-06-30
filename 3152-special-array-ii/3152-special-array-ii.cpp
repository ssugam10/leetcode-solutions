class Solution {
public:
    void findSpecialIntervals(vector<int>& nums, vector<int>& till, int n) {
        bool parity = (nums[n-1]%2==0)?1:0; //even=> 1, odd => 0
        int pIdx = n-1;
        till[n-1] = n-1;
        for(int i = n-2; i>=0; i--){
            bool currParity = (nums[i]%2==0)?1:0;
            if(parity != currParity){
                till[i] = pIdx;
            }
            else{
                pIdx = i;
                till[i] = i;  
            }
            parity = (nums[i]%2==0)?1:0;
        }
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> ans;
        vector<int> till(n);
        findSpecialIntervals(nums,till,n);

        for (vector<int>& query : queries) {
            int start = query[0];
            int end = query[1];
            if(till[start] >= end){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }

        return ans;
    }
};
