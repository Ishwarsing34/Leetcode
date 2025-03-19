class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        stack<int> st;

        vector<int> ans(p.size());

        for (int i = p.size() - 1; i >= 0; i--) {

            while (!st.empty() && st.top() > p[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? p[i] : abs(st.top() - p[i]);

            st.push(p[i]);
        }

        return ans;
    }
};