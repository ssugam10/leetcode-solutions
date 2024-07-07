#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    
    long long findVal(vector<int> bits, int w){ //Function to find the and value
        int ans = 0;
        for(int i = 0; i<32; i++){
            if(bits[i] == w){
                ans |= (1 << i);
            }
        }
        return ans;
    }
    
    long long andAtleastK(vector<int>& nums, int k){
        vector<int> bits(32);
        int n = nums.size();
        
        long long count = 0;
        int l = 0;
        for(int r = 0; r<n; r++){
            
            for(int i = 0; i<32; i++){
                if(nums[r] & (1 << i))  bits[i]++;
            }
            
            while(r - l + 1 > 0 && findVal(bits,r - l + 1) < k){
                for(int i = 0; i<32; i++){
                    if(nums[l] & (1 << i)){
                        bits[i]--;
                    }
                }
                l++;
            }
            
            count += (r - l + 1);   //adding the count of subarrays ending at r,
                                    //with AND value of greater than or equal to k
        }
        
        return count;
    }
    
    long long countSubarrays(vector<int>& nums, int k) {
        return andAtleastK(nums,k) - andAtleastK(nums,k+1);
    }
};
