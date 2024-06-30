class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());   //O(n)

        int sum = 0;
        for(int i = 0; i<nums.size(); i++){ //O(n)
            sum += nums[i]; 
        }

        while(k--){ //O(klogn)
            int ele = pq.top(); //minimum element
            if(ele == 0)    break;

            pq.pop();   //remove the smallest
            pq.push(-1*ele);    //add the negated value into the priority queue

            sum -= (2*ele);
        }

        return sum;
    }
};