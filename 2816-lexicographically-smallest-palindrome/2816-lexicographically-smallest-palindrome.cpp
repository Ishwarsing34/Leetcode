class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();

        int i = 0;
        int j = n - 1;

        while (i < n) {

            if (s[i] != s[j]) {
                if (s[i] > s[j]) {
                    s[i] = s[j];
                } else {
                    s[j] = s[i];
                }
            }
            i++, j--;
        }

        return s;
    }
};