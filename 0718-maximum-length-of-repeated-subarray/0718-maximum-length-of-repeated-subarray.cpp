class Solution {
public:
    int n;
    int m;

    vector<vector<int>> dp;

    int f(int i, int j, vector<int>& nums1, vector<int>& nums2){

        if(i >= n || j >= m)    return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        int ans = 0;

        if(nums1[i] == nums2[j]){
            int k = i;
            int l = j;
            while(k < n && l < m && nums1[k] == nums2[l]){
                k++;
                l++;
            }
            ans = k-i;
        }

        ans = max({ans,f(i+1,j,nums1,nums2),f(i,j+1,nums1,nums2)});
        return dp[i][j] = ans;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();

        dp.clear();
        dp.resize(n+1,vector<int>(m+1,-1));

        return f(0,0,nums1,nums2);
    }
};