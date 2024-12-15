#define pi pair<double, pair<int, int>>

class Solution {
public:
    double incr(int pass, int total) {
        return (1.0 * (pass + 1) / (total + 1)) - (1.0 * pass / total);
    }
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pi> pq;

        // Initialize the priority queue with the initial increments
        for (int i = 0; i < n; i++) {
            int pass = classes[i][0];
            int total = classes[i][1];
            pq.push({incr(pass, total), {pass, total}});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto top = pq.top();
            pq.pop();

            int pass = top.second.first;
            int total = top.second.second;

            pq.push({incr(pass + 1, total + 1), {pass + 1, total + 1}});
        }

        // Calculate the final average ratio
        double avg = 0.0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int pass = top.second.first;
            int total = top.second.second;

            avg += (1.0 * pass / total);
        }

        avg /= n;
        return avg;
    }
};
