#define ll long long int
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ll score = 0;
        
        int n = nums.size();
        
        priority_queue<int> pq(nums.begin(),nums.end());
        
        while(k--){
            score += pq.top();
            pq.push(ceil(pq.top() * 1.0/ 3));
            pq.pop();
        }
        
        return score;
    }
};