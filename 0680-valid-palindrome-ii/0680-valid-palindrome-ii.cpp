class Solution {
    bool checkPal(string s, int st, int en) {

        while (st < en) {

            if (s[st] != s[en])
                return false;
            else
                st++, en--;
        }

        return true;
    }

public:
    bool validPalindrome(string s) {
        int n = s.size();

        int st = 0;
        int en = n - 1;

        while (st < en) {

            if (s[st] == s[en]) {
                st++, en--;
            } else {

                return checkPal(s, st + 1, en) || checkPal(s, st, en - 1);
            }
        }

        return true;
    }
};