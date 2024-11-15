class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int left = 0;
        
        for(int i = 1; i<n; i++){
            if(arr[i] >= arr[i - 1])    left = i;
            else break;
        }
        
        if(left == n - 1)   return 0;
        
        int right = n - 1;
        for(int i = n - 2; i>=0; i--){
            if(arr[i] <= arr[i + 1])     right = i;
            else break;
        }
        
        
        int i = 0, j = right;
        
        int remove = min(n - left - 1, right);
        
        while(i <= left && j < n){
            if(arr[i] <= arr[j]){
                remove = min(remove, j - i - 1);  
                i++;    //Try to make the removed subarray smaller
            }      
            else j++;
        }
        
        return remove;
    }
};