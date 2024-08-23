#include <vector>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

class Solution {
public:
    ll maximumValueSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        ll maxSum = LLONG_MIN;
        
        // Store the top 3 values in each row
        vector<vector<pair<ll, pair<int, int>>>> topThreeValues(rows, vector<pair<ll, pair<int, int>>>(3, {LLONG_MIN, {-1, -1}}));
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                ll currentValue = matrix[r][c];
                if (currentValue > topThreeValues[r][2].first) {
                    topThreeValues[r][2] = {currentValue, {r, c}};
                    
                    if (topThreeValues[r][1].first < topThreeValues[r][2].first) {
                        swap(topThreeValues[r][1], topThreeValues[r][2]);
                        
                        if (topThreeValues[r][0].first < topThreeValues[r][1].first) {
                            swap(topThreeValues[r][0], topThreeValues[r][1]);
                        }
                    }
                }
            }
        }
        
        // Calculate the maximum sum using different combinations of rows
        for (int r1 = 0; r1 < rows; r1++) {
            for (int r2 = r1 + 1; r2 < rows; r2++) {
                for (int r3 = r2 + 1; r3 < rows; r3++) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            for (int k = 0; k < 3; k++) {
                                int col1 = topThreeValues[r1][i].second.second;
                                int col2 = topThreeValues[r2][j].second.second;
                                int col3 = topThreeValues[r3][k].second.second;
                                
                                if (col1 == col2 || col1 == col3 || col2 == col3) continue;
                                
                                maxSum = max(maxSum, (ll)(matrix[r1][col1]) + (ll)(matrix[r2][col2]) + (ll)(matrix[r3][col3]));
                            }
                        }
                    }
                }
            }
        }
        
        return maxSum;
    }
};
