class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> psi(n), nsi(n);

        stack<int> st;
        // Calculate psi (previous smaller index)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            psi[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear the stack for reuse
        while (!st.empty()) st.pop();

        // Calculate nsi (next smaller index)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            nsi[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sumMins = 0;
        for (int i = 0; i < n; ++i) {
            int left = i - psi[i];
            int right = nsi[i] - i;
            sumMins += (long long)left * right * arr[i];
        }

        return sumMins;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> pgi(n), ngi(n);

        stack<int> st;
        // Calculate pgi (previous greater index)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            pgi[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear the stack for reuse
        while (!st.empty()) st.pop();

        // Calculate ngi (next greater index)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ngi[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sumMaxs = 0;
        for (int i = 0; i < n; ++i) {
            int left = i - pgi[i];
            int right = ngi[i] - i;
            sumMaxs += (long long)left * right * arr[i];
        }

        return sumMaxs;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long sumMins = sumSubarrayMins(nums);
        long long sumMaxs = sumSubarrayMaxs(nums);
        return sumMaxs - sumMins;
    }
};
