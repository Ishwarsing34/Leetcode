class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {

        stack<int> st;

        int n = a.size();

        for (int i = 0; i < n; i++) {

            while (!st.empty() && a[i] < 0 && st.top() > 0) {
                int sum = a[i] + st.top();

                if (sum > 0) {
                    a[i] = 0;

                } else if (sum < 0) {
                    

                    st.pop();
                } else {
                    a[i] = 0;
                    st.pop();
                }
            }

            if (a[i] != 0) {
                st.push(a[i]);
            }
        }

        int m = st.size();

        vector<int> ans(m);

        int i = m - 1;

        while (!st.empty()) {
            ans[i] = st.top();
            st.pop();
            i--;
        }

        return ans;
    }
};