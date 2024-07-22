class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(),score.end(), [k](vector<int> &row1, vector<int> &row2){
            return row1[k] >= row2[k];
        });
        
        return score;
    }
};