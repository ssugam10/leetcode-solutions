#define ll long long int
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        
        vector<int> factors(mx+1,0);
        
        //storing all the factors of all the numbers : factors  lie in the range 1 to mx
        for(auto ele : nums){
            for(int i = 1; i * i <= ele; i++){
                if(ele % i == 0){
                    factors[i]++;
                    
                    if(ele / i != i){
                        factors[ele / i]++;
                    }
                }
            }
        }
        
        //gcdCount[i] stores the number of pairs with gcd as i
        vector<ll> gcdCount(mx+1,0);
        
        for(int i = mx; i>=1; i--){
            ll pairs = (1LL * factors[i] * (factors[i] - 1)) / 2;
            gcdCount[i] = pairs;
            
            //i ke sare multiples <= mx ka contribution ghatana hoga kyuki agar vo factor hai toh i toh pakka hi hoga
            for(int r = 2 * i; r <= mx; r += i){
                gcdCount[i] -= gcdCount[r];
            }
        }
        
        vector<ll> pre(mx+1,0);
        pre[1] = gcdCount[1];
        
        //so that we can binary search for reqd index
        for(int i = 2; i<=mx; i++){
            pre[i] = pre[i - 1] + gcdCount[i];
        }
        
        vector<int> ans;
        
        
        for(auto idx : queries){
            int lo = 1;
            int hi = mx;
            
            while(lo <= hi){
                int mid = lo + (hi - lo) / 2;
                
                if(pre[mid] > idx){
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
            
            ans.push_back(lo);
        }
        
        return ans;
    }
};