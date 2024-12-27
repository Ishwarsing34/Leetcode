class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();

        vector<int> prev(n, -1);
        vector<int> nxt(n, n);

        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }

            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // stack<int>nxt;

        while(!st.empty())
        {
            st.pop();
        }


        for(int i=n-1;i>=0;i--){

            while(!st.empty() && h[st.top()] >= h[i])
            {
                st.pop();
            }

            nxt[i] = st.empty() ? n : st.top();
            st.push(i);
        }


        int area = 0;

        for(int i=0;i<n;i++) 
        {
            int width = (nxt[i] - prev[i] - 1) * h[i];
            area = max(width,area);
        }

        return area;
    }
};