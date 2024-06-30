class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 1;
        int hi = arr.size() - 2;    //first and last element cannot be peak elements
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid+1] < arr[mid] && arr[mid-1] < arr[mid]){
                return mid;
            }
            else if(arr[mid+1] < arr[mid]){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return -1;
    }
};