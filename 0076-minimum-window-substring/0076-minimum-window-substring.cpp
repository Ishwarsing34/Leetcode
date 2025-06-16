class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        int cnt = t.size();  

        map<char, int> mp;
        for (auto ch : t) {
            mp[ch]++;
        }

        int i = 0, j = 0;
        int startInd = 0;
        int minLen = INT_MAX;

        while (j < n) {
            if (mp.count(s[j])) {
                mp[s[j]]--;
                if (mp[s[j]] >= 0)
                    cnt--;
            }

            while (cnt == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    startInd = i;
                }

                if (mp.count(s[i])) {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                        cnt++;
                }

                i++;
            }

            j++;
        }

        return minLen == INT_MAX ? "" : s.substr(startInd, minLen);
    }
};
