class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.size();

        stack<char> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && st.top() - '0' > num[i] - '0' && k > 0) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        while (k > 0) {
             k--;
            st.pop();
           
        }

        string res = "";

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        int i = 0;

        while (res[i] == '0') {
            i++;
        }

        res = res.substr(i);

        return res.size() == 0 ? "0" : res;
    }
};