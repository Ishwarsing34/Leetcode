

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> prevsmall(n, -1); // Replace VLAs with vectors
        vector<int> nextsmall(n, n); // Replace VLAs with vectors

        stack<int> st;

        // Find previous smaller elements
        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }
            prevsmall[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        stack<int> nxt;

        // Find next smaller elements
        for (int i = n - 1; i >= 0; i--) {
            while (!nxt.empty() && h[nxt.top()] >= h[i]) {
                nxt.pop();
            }
            nextsmall[i] = nxt.empty() ? n : nxt.top();
            nxt.push(i);
        }

        // Calculate the maximum area
        int area = 0;
        for (int i = 0; i < n; i++) {
            int width = nextsmall[i] - prevsmall[i] - 1;
            area = max(area, width * h[i]);
        }

        return area;
    }
};
