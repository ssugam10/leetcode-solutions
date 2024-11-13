#define ll long long int

class FindSumPairs {
public:
    vector<int> arr1,arr2;
    
    int m,n;
    
    map<ll,ll> freq;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        
        m = arr1.size();
        n = arr2.size();
        
        for(int i = 0; i<n; i++){
            freq[arr2[i]]++;
        }
        
    }
    
    void add(int index, int val) {
        freq[arr2[index]]--;
        arr2[index] += val;
        freq[arr2[index]]++;
    }
    
    int count(int tot) {
        int count = 0;
        
        for(int i = 0; i<m; i++){
            count += freq[tot - arr1[i]];
        }
        
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */