#define pi pair<int, int> 
class Solution {
public:
    vector<bool> isPrime;
    
    void sieveOfEratosthenes() {
        const int MAX_VAL = 100000;
        isPrime.resize(MAX_VAL + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int p = 2; p * p <= MAX_VAL; ++p) {
            if (isPrime[p]) {
                for (int i = p * p; i <= MAX_VAL; i += p) {
                    isPrime[i] = false;
                }
            }
        }
    }
    
    int minOperations(int n, int m) {
        const int MAX_VAL = 100000;
        sieveOfEratosthenes();
        
        if (isPrime[n] || isPrime[m]) return -1; // Invalid initial or final states
        
        vector<int> dist(MAX_VAL + 1, INT_MAX);
        dist[n] = 0;
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({n, n});
        
        while (!pq.empty()) {
            auto [cost, num] = pq.top();
            pq.pop();
            
            if (num == m) return cost;
            
            string numStr = to_string(num);
            for (int i = 0; i < numStr.size(); ++i) {
                char original = numStr[i];
                
                // Increment digit
                if (original < '9') {
                    numStr[i] = original + 1;
                    int nextNum = stoi(numStr);
                    if (nextNum <= MAX_VAL && !isPrime[nextNum] && cost + nextNum < dist[nextNum]) {
                        dist[nextNum] = cost + nextNum;
                        pq.push({dist[nextNum], nextNum});
                    }
                }
                
                // Decrement digit
                if (original > '0') {
                    numStr[i] = original - 1;
                    int nextNum = stoi(numStr);
                    if (nextNum <= MAX_VAL && !isPrime[nextNum] && cost + nextNum < dist[nextNum]) {
                        dist[nextNum] = cost + nextNum;
                        pq.push({dist[nextNum], nextNum});
                    }
                }
                
                // Restore original digit
                numStr[i] = original;
            }
        }
        
        return -1; // Transformation not possible
    }
};
