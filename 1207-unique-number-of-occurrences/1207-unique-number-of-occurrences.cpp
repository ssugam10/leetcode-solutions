class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();

        for(int i = 0 ; i<n; i++){
            mp[arr[i]]++;
        }

        unordered_set<int> s;
        for(auto ele : mp){
            if(s.find(ele.second) != s.end()){
                return false;
            }
            s.insert(ele.second);
        }

        return true;
    }
};