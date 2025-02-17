class Solution {

    void solve(int ind, vector<string>& ans, string str, string& s) {

        if (str.size() == s.size()) {
            ans.push_back(str);
            return;
        }

        if (s[ind] >= '0' && s[ind] <= '9') {
            solve(ind + 1, ans, str + s[ind], s);
        } else {
            solve(ind + 1, ans, str + (char)(toupper(s[ind])), s);
            solve(ind + 1, ans, str + (char)(tolower(s[ind])), s);
        }
        return;
    }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string str = "";
        solve(0, ans, str, s);

        return ans;
    }
};