class Solution {
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i < k; i++) {

            if (isVowel(s[i])) {
                cnt++;
            }
        }

        int max_cnt = cnt;

        for (int st = 1, en = k; en < n; st++, en++) {

            if (isVowel(s[st - 1]))
                cnt--;
            if (isVowel(s[en]))
                cnt++;

            max_cnt = max(max_cnt, cnt);
        }

        return max_cnt;
    }
};