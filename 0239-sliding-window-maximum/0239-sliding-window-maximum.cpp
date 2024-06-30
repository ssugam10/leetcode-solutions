class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1) return nums;
        deque<int> dq;  //decreasing order of element
        vector<int> ans;    // i should be min k-1
        int n = nums.size();
        for(int i = 0; i<n; i++){
            while(dq.size()>0 && nums[i]>nums[dq.back()]) dq.pop_back();
            dq.push_back(i);    
            while(dq.front() < i-k+1)   dq.pop_front(); //i-k+1 is the starting index of the window
            if(i>=k-1)  ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};