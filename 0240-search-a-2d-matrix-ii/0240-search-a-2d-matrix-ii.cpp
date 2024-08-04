class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int ro = 0;
        int co = m - 1;
        
        while(ro < n && co >= 0){
            if(matrix[ro][co] == target)    return true;
            else if(matrix[ro][co] > target)    co--;
            else ro++;
        }
        
        return false;
    }
};