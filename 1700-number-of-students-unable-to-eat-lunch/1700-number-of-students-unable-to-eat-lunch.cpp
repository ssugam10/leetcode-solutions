class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int idx = 0;    //represents the sandwich stack using indices on vectors
        queue<int> q;
        int n = sandwiches.size();
        for(int i = 0; i<n; i++){
            q.push(students[i]);
        }
        int consecutiveFails = 0;
        while(idx<n){
            if(consecutiveFails >= n-idx)   break;  //n-idx is the current length of the queue
            if(q.front() == sandwiches[idx]){
                consecutiveFails = 0;
                q.pop();
                idx++;
            }
            else{
                q.push(q.front());
                q.pop();
                consecutiveFails++;
            }
        }

        return q.size();
    }
};