#define ll long long int
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        ll mx = INT_MIN;
        ll prod = 1;
        
        for(int i = 0; i<n; i++){
            prod *= nums[i];
            mx = max(mx,prod);
            if(prod == 0 || prod < INT_MIN)   prod = 1;
        }
        
        prod = 1;
        for(int i = n - 1; i>=0; i--){
            prod *= nums[i];
            mx = max(mx,prod);
            if(prod == 0 || prod < INT_MIN)   prod = 1;
        }
        
        return (int)mx;
    }
};