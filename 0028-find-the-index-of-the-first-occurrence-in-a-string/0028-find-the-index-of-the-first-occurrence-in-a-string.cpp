class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i = 0; i<n; i++){
            if(haystack[i] == needle[0]){
                int j = i + 1;
                int k = 1;
                while(j < n && k<m && needle[k] == haystack[j]){
                    k++;
                    j++;
                }
                if(k == m)  return i;
            }
        }

        return -1;
    }
};