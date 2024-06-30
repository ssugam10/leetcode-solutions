class cmp{
    public:
    bool operator()(const pair<int,string> p1, pair<int,string> p2){
        if(p1.first == p2.first)    return p1.second > p2.second;
        return p1.first < p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        vector<string> ans;

        for(auto ele : words){
            mp[ele]++;
        }

        priority_queue< pair<int,string>, vector<pair<int,string>>, cmp> pq;
        for(auto ele : mp){
            pq.push({ele.second,ele.first});
        }

        while(k--){
            auto curr = pq.top();
            pq.pop();
            ans.push_back(curr.second);
        }

        return ans;
    }
};