class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n),right(n);
        
        int mx = height[0];
        for(int i = 0; i<n; i++){
            mx = max(mx,height[i]);
            left[i] = mx;
        }
        
        int mex = height[n-1];
        for(int i = n - 1; i>=0; i--){
            mex = max(mex,height[i]);
            right[i] = mex;
        }
        
        
        int cnt = 0;
        for(int i = 0; i<n; i++){
            cnt += (min(left[i],right[i]) - height[i]);
        }
        
        return cnt;
    }
};