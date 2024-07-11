class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0; i<n; i++){
            for(int j = 1; j<m ; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        //we have created the prefix sum matrix along the rows
        
        
        unordered_map<int,int> mp;
        
        int ans = 0;
        
        for(int i = 0; i<m; i++){   //start col
            for(int j = i; j<m; j++){   //end col
                mp = {{0,1}};
                
                int sum = 0;
                for(int k = 0; k<n; k++){
                    int currSum = matrix[k][j] - ((i > 0) ? matrix[k][i-1] : 0);  //sum of the row range between given cols
                    sum += currSum;
                    
                    ans += mp[sum - target];
                    mp[sum]++;
                }
            }
        }
        
        return ans;
    }
};