class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();

        int depth = 0;
        char prev = '(';
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                depth++;
            else {
                depth--;
                if (prev == '(') {
                    ans += pow(2, depth);
                }
            }

            prev = s[i];
        }

        return ans;
    }
};