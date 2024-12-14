#define ll long long int

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        ll count = 0;
        
        multiset<int> st;
        
        int i = 0, j = 0;
        
        while(j < n){
            st.insert(nums[j]);
            
            while(*(st.rbegin()) - *(st.begin()) > 2){
                
                //count the subarrays starting with i
                count += (j - i);
                
                auto it = st.find(nums[i]);
                if(it != st.end())  st.erase(it);
                
                i++;
            }
            
            j++;
        }
        
        ll val = j - i;
        
        count += val * (val + 1) / 2;
        
        return count;
    }
};