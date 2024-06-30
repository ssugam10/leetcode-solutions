class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int ct = 0;
        vector<int> v(n,0);
        int j = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] != val){
                ct++;
                v[j++] = nums[i]; 
            }
        }

        for(int i = 0; i<v.size(); i++){
            nums[i] = v[i];
        }

        return ct;
    }
};