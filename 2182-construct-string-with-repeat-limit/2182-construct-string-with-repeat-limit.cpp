class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;
        for(int i = 0; i<s.size(); i++){    //storing characters and their frequencies in unordered map
            mp[s[i]]++;
        }

        string result = "";

        priority_queue<pair<char,int>> pq;
        for(auto p : mp){
            pq.push(p);
        }

        while(!pq.empty()){
            auto largest = pq.top();
            pq.pop();
            int len = min(largest.second,repeatLimit);

            for(int i = 0; i<len; i++)  result += largest.first;

            largest.second -= len;
            if(largest.second > 0){
                if(!pq.empty()){
                    auto secondLargest = pq.top();
                    pq.pop();
                    result += secondLargest.first;
                    secondLargest.second--;
                    if(secondLargest.second > 0)    pq.push({secondLargest.first,secondLargest.second});
                    pq.push({largest.first,largest.second});
                }
                else{
                    return result;
                }
            }
        }
        return result;
    }
};