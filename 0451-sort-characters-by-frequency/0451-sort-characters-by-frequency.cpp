#define pp pair<int,char>

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
        } 
        priority_queue<pp> pq;

        for(auto ele : mp){
            int key = ele.first;
            int value = ele.second;
            pq.push({value,key}); 
        }

        string str = "";
        while(!pq.empty()){
            pp curr = pq.top();
            pq.pop();
            for(int i = 0; i<curr.first; i++){
                str += curr.second;
            }
        }

        return str;
    }
};