class Solution {
public:
    bool find(long long t, int h, vector<int>& wt) {
        long long totalH = 0;

        for (int w : wt) {
            long long left = 0, right = 1e6;
            while (left <= right) {
                long long mid = left + (right - left) / 2;
                
                // Avoid overflow by rearranging the multiplication
                if (mid * (mid + 1) / 2 <= t / w) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            totalH += right;
            if (totalH >= h) return true;
        }
        return totalH >= h;
    }

    long long minNumberOfSeconds(int height, vector<int>& w) {
        if(w.size()==1){
            return ((height * 1ll * (height + 1)) / 2) * w[0];
        }
        
        sort(w.begin(), w.end());
        
        long long l = 1, h = 1e8, ans = h;

        while (l <= h) {
            long long mid = l + (h - l) / 2;
            if (find(mid, height, w)) {
                h = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
