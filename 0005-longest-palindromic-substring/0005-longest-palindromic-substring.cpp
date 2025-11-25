class Solution {
    bool checkPal(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkPal(s, i, j)) {
                    int len = j - i + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        res = s.substr(i, len);
                    }
                }
            }
        }

        return res;
    }
};
