class Solution {
public:
    bool isAnagram(string s, string t) {

        int n = s.size();

        int m = t.size();

        if (n != m)
            return false;

        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);

        for (int i = 0; i < n; i++) {

            cnt1[s[i] - 'a']++;
            cnt2[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i])
                return false;
        }

        return true;
    }
};