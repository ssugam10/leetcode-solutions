class Solution {
public:
    int maxProduct(vector<int>& nums) {
    double maxi = INT_MIN;
    double prod=1;

        for(int i=0;i<nums.size();i++)
        {
          prod*=nums[i];
          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
          prod*=nums[i];

          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        return (int) maxi;
    }
};

// #define ll long long int
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
        
//         ll mx = INT_MIN;
//         ll prod = 1;
        
//         for(int i = 0; i<n; i++){
//             prod *= nums[i];
//             mx = max(mx,prod);
//             if(prod == 0 || prod < INT_MIN)   prod = 1;
//         }
        
//         prod = 1;
//         for(int i = n - 1; i>=0; i--){
//             prod *= nums[i];
//             mx = max(mx,prod);
//             if(prod == 0 || prod < INT_MIN)   prod = 1;
//         }
        
//         return (int)mx;
//     }
// };

