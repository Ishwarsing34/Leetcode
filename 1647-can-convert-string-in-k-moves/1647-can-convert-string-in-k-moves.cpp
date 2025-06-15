class Solution {
public:
    bool canConvertString(string s, string t, int k) {

        if (s.size() != t.size())
            return false;

        map<int, int> mp;
        int maxi = INT_MIN;

        for (int i = 0; i < s.size(); i++) {
            int a = s[i];
            int b = t[i];

            int diff = (b - a + 26) % 26;

            if (diff == 0)
                continue;

            if (mp.count(diff)) {
                mp[diff] += 26;
                maxi = max(maxi, mp[diff]);
            } else {
                mp[diff] = diff;
                maxi = max(maxi, mp[diff]);
            }
        }

        return maxi <= k;
    }
};