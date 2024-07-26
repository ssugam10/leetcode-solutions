#define ll long long int
class Solution {
public:
    int MOD = 1e9+7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        int i = 0;
        int j = 0;
        ll sum1 = 0;
        ll sum2 = 0;
        ll sum = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                sum1 += nums1[i];
                i++;
            } else if (nums1[i] > nums2[j]) {
                sum2 += nums2[j];
                j++;
            } else {
                sum += nums1[i] + max(sum1, sum2);
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
            
        }
        
        while(i < n){
            sum1 += nums1[i];
            i++;
        }
        
        while(j < m){
            sum2 += nums2[j];
            j++;
        }
        
        sum += max(sum1, sum2);
        
        
        sum = sum % MOD;
        
        return (int)sum;
    }
};
