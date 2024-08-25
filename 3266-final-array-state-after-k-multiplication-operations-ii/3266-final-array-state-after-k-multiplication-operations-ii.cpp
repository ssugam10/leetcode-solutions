#define ll long long int
#define pi pair<ll,ll>

class Solution {
public:
    const int mod = 1e9 + 7;
        
    ll pow(ll base, ll exp){
        ll result = 1;
        while(exp){
            if(exp & 1){
                result *= base;
                result %= mod;
            }   
            base *= base;
            base %= mod;
            exp >>= 1;
        }
        
        return result;
    }
    
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier == 1) return nums;
        
        int n = nums.size();
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        for(int i = 0; i<n; i++){
            pq.push({nums[i],i});
        }
        
        int mx = *max_element(nums.begin(),nums.end());
        
        while(k && (pq.top().first * multiplier) <= mx){
            int idx = pq.top().second;
            nums[idx] = pq.top().first * multiplier;
            
            pq.pop();
            
            pq.push({nums[idx],idx});
            k--;
            
        }
        
        
        
        ll common = pow(multiplier, k / n);
        
        while(!pq.empty()){
            ll val = pq.top().first;
            ll idx = pq.top().second;
            pq.pop();
            
            if(k % n){
                nums[idx] = (int)(((val * common) % mod * multiplier) % mod);
                k--;
            }
            else{
                nums[idx] = (int)((val * common) % mod);
            }
        }
        
        return nums;
    }
};