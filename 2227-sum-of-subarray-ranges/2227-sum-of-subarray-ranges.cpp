class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL(n, -1), NSR(n, n);
        vector<int> NGL(n, -1), NGR(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            NSL[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            NSR[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            NGL[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            NGR[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sumMin = 0, sumMax = 0;

        for (int i = 0; i < n; i++) {
            long long leftMin = i - NSL[i];
            long long rightMin = NSR[i] - i;
            sumMin += arr[i] * leftMin * rightMin;

            long long leftMax = i - NGL[i];
            long long rightMax = NGR[i] - i;
            sumMax += arr[i] * leftMax * rightMax;
        }

        return sumMax - sumMin;
    }
};
