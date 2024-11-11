#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> isPrime;
    vector<int> primes;

    Solution() : isPrime(2000, true) {
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= 1005; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 1005; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i <= 2000; i++) {
            if (isPrime[i]) primes.push_back(i);
        }
    }

    int check(int a, int b) {
        auto search = upper_bound(primes.begin(), primes.end(), a - b);
        a -= (*search);
        return (a <= 0) ? -1 : a;
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) continue;
            
            int ans = check(nums[i], nums[i + 1]);
            if (ans == -1) return false;
            nums[i] = ans;
        }
        return true;
    }
};
