class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {

        int n = ast.size();

        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && st.top() > 0 && ast[i] < 0) {

                int sum = st.top() + ast[i];

                if (sum > 0) {
                    ast[i] = 0;
                } else if (sum < 0) {
                    st.pop();
                } else {
                    st.pop();
                    ast[i] = 0;
                }
            }

            if (ast[i] != 0) {
                st.push(ast[i]);
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