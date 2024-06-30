class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++){
            mp[answers[i]+1]++;
        }

        int count = 0;
        for(auto ele : mp){
            count += ((ele.first) * (ele.second/(ele.first) ));
            if(ele.second % ele.first != 0) count+=ele.first;
        }
        return count;
    }
};