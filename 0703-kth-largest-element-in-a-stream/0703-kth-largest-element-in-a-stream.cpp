class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> mn_pq; //min-heap
    
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        int n = nums.size();
        for(int i = 0; i<n; i++){
            addEle(nums[i]);
        }
    }
    
    void addEle(int ele){
        int mn = mn_pq.size();
        if(mn < k){
            mn_pq.push(ele);
        }
        else{
            if(ele > mn_pq.top()){
                mn_pq.pop();
                mn_pq.push(ele);
            }
        }
    }
    
    int add(int val) {
        addEle(val);
        if(mn_pq.size() >= k)   return mn_pq.top();
        
        return -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */