class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        int n = p.size();

        stack<int>st;
        vector<int>ans(n);

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()>p[i])
            {
                st.pop();
            }

            ans[i] = st.empty() ? p[i] :abs (p[i] - st.top());

            st.push(p[i]);
        }

        return ans;
    }
};