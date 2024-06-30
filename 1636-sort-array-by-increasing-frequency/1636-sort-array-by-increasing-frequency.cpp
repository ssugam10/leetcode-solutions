#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

#define pi pair<int, int>

class Solution {
public:
    struct cmp {
        bool operator()(pi a, pi b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

    vector<int> frequencySort(vector<int>& nums) {
        priority_queue<pi, vector<pi>, cmp> pq;

        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (auto ele : mp) {
            pq.push({ele.second, ele.first});
        }

        vector<int> ans;
        while (!pq.empty()) {
            int num = pq.top().second;
            int freq = pq.top().first;
            pq.pop();

            while (freq--) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};
