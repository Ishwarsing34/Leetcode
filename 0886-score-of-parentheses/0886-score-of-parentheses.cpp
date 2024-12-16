class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0;
        int res = 0;
        char prev = '(';

        for (char& ch : s) {
            if (ch == '(') {
                depth++;
            } else {
                depth--;
                if (prev == '(') {
                    res += pow(2, depth);
                }
            }

            prev = ch;
        }

        return res;
    }
};