class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string res = "";

        stack<char> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && k > 0 && st.top() - '0' > num[i] - '0') {

                k--;
                st.pop();
            }
            st.push(num[i]);
        }

        while (k > 0) {
            k--;
            st.pop();
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());

        while (res.size() > 0 && res[0] == '0') {
            res.erase(res.begin());
        }

        return res.empty() ? "0" : res;
    }
};