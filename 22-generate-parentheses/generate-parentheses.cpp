class Solution {
    void solve(string temp, int left, int right, vector<string>& ans, int n) {

        if (left + right >= 2 * n) {
            ans.push_back(temp);
            return;
        }

        if (left < n) {

            temp.push_back('(');
            solve(temp, left + 1, right, ans, n);
            temp.pop_back();
        }

        if (right < left) {

            temp.push_back(')');
            solve(temp, left, right + 1, ans, n);
            temp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        int left = 0;
        int right = 0;

        string temp = "";

        solve(temp, left, right, ans, n);

        return ans;
    }
};