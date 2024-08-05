class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> psi(n), nsi(n);
        const int MOD = 1e9 + 7;

        stack<int> st;
        // Calculate psi (previous smaller index)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            psi[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        stack<int> s;
        // Calculate nsi (next smaller index)
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            nsi[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long cnt = 0;
        for (int i = 0; i < n; ++i) {
            int left = i - psi[i];
            int right = nsi[i] - i;
            cnt = (cnt + (long long)left * right * arr[i]) % MOD;
        }

        return cnt;
    }
};
