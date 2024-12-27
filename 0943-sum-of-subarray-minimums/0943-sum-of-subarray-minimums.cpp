class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int M = 1e9 + 7;

        vector<int> NSL(n, -1);
        vector<int> NSR(n, n);

        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            NSL[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            NSR[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - NSL[i];
            long long right = NSR[i] - i;
            long long totalWays = (left * right) % M;
            long long totalSum = (arr[i] * totalWays) % M;

            sum = (sum + totalSum) % M;
        }

        return sum;
    }
};
