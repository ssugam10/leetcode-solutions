class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> arr1(arr.begin(), arr.end());
        sort(arr1.begin(), arr1.end());
        
        map<int, int> mp, mp1;
        int c = 0; // Counter for chunks
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
            mp1[arr1[i]]++;
            
            // Check if the frequency maps are equal
            if (mp == mp1) {
                c++;        // Increment chunk count
                mp.clear(); // Clear the maps for the next chunk
                mp1.clear();
            }
        }
        
        return c;
    }
};
