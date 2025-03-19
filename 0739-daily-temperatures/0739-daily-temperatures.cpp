class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temp[st.top()] <= temp[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? 0 : abs(st.top() - i);

            st.push(i);
        }

        return ans;
    }
};