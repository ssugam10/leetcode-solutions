class Solution {
public:
    int rev(int n){
        int num = 0;
        while(n>0){
            num*=10;
            int digit = n % 10;
            num += digit;
            n/=10;
        }
        return num;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        int cnt = 0;
        for(int i = 0; i<n; i++){
            int key = nums[i] - rev(nums[i]);
            if(mp.find(key) != mp.end()){
                cnt = cnt%1000000007;
                cnt += mp[key];
            }
            mp[key]++;
        }

        return cnt%1000000007;
    }
};