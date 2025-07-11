class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        int cnt = 0;
        string res = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                cnt++;
                if (cnt > 1) {
                    res.push_back(s[i]);
                }
            } else {
                cnt--;
                if (cnt > 0) {
                    res.push_back(s[i]);
                }
            }
        }

        return res;
    }
};