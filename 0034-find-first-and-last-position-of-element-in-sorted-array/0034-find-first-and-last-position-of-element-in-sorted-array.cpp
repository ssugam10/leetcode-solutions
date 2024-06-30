#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeftBoundary(nums, target);
        int right = findRightBoundary(nums, target);

        return {left,right};
    }

private:
    int findLeftBoundary(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int leftBoundary = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target) {
                if (nums[mid] == target) {
                    leftBoundary = mid;
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return leftBoundary;
    }

    int findRightBoundary(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int rightBoundary = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target) {
                if (nums[mid] == target) {
                    rightBoundary = mid;
                }
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return rightBoundary;
    }
};