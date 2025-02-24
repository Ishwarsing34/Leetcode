class Solution {

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    };

public:
    int maxVowels(string s, int k) {
        int n = s.size();

        int i = 0;
        int j = 0;
        int cnt = 0;
        int maxxi = INT_MIN;

        while (j < n) {
            if (isVowel(s[j])) {
                cnt++;
            }

            if (j - i + 1 == k) {

                maxxi = max(maxxi, cnt);
                if (isVowel(s[i])) {
                    cnt--;
                }

                i++;
            }

            j++;
        }

        return maxxi;
    }
};