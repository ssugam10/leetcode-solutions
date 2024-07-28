#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // Ensure nums1 is the smaller array for binary search efficiency
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n = n1 + n2;
        int left = (n + 1) / 2; // The number of elements in the left partition of the combined array

        int lo = 0, hi = n1;
        while (lo <= hi) {
            int mid1 = lo + (hi - lo) / 2;  // Midpoint for nums1
            int mid2 = left - mid1; // Corresponding midpoint for nums2
            
            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN; // Left max in nums1
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN; // Left max in nums2
            int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX; // Right min in nums1
            int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX; // Right min in nums2
            
            // Check if we have found the correct partition
            if (l1 <= r2 && l2 <= r1) {
                if (n & 1) {
                    return max(l1, l2); // Odd length case
                } else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0; // Even length case
                }
            } else if (l1 > r2) {
                hi = mid1 - 1; // Move towards left in nums1
            } else {
                lo = mid1 + 1; // Move towards right in nums1
            }
        }
        
        return 0.0; // This line should never be reached if input arrays are valid
    }
};
