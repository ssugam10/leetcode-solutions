class Solution {
public:
    int f(vector<int>& nums, int i, int n) {
        int cnt = 1;
        bool parity = nums[i] % 2 == 0;
        
        for (int j = i + 1; j < n; j++) {
            bool current_parity = nums[j] % 2 == 0;
            if (current_parity != parity) {
                cnt++;
                parity = !parity;  // Toggle parity for the next expected parity
            }
        }
        
        return cnt;
    }
    
    
    
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
    
        
        bool oddFlag = false;
        bool evenFlag = false;
        int maxLength = 0;
        int possible = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1 && !oddFlag) {
                oddFlag = true;
                maxLength = max(maxLength, f(nums, i, n));
            } else if (nums[i] % 2 == 0 && !evenFlag) {
                evenFlag = true;
                maxLength = max(maxLength, f(nums, i, n));
            }
            
            if (oddFlag && evenFlag) {
                break;
            }
        }
        
        int even = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] % 2 == 0){
                even++;
            }
        }
        
        return max({even,n-even,maxLength});
        
        
    }
};
