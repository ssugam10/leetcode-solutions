#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> frequencyMap;
        for (char task : tasks) {
            frequencyMap[task]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto& entry : frequencyMap) {
            pq.push({entry.second, entry.first});
        }

        int time = 0;
        queue<pair<int, char>> cooldownQueue;  // {time available, task}

        while (!pq.empty() || !cooldownQueue.empty()) {
            time++;

            if (!cooldownQueue.empty() && cooldownQueue.front().first == time) {
                auto front = cooldownQueue.front();
                cooldownQueue.pop();
                pq.push({frequencyMap[front.second], front.second});
            }

            if (!pq.empty()) {
                auto current = pq.top();
                pq.pop();
                frequencyMap[current.second]--;

                if (frequencyMap[current.second] > 0) {
                    cooldownQueue.push({time + n + 1, current.second});
                }
            }
        }

        return time;
    }
};
