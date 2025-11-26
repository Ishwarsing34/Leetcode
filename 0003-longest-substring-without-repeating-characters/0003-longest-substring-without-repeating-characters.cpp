class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();

        map<int, int> mp;

        int len = 0;
        int i = 0;

        int j = 0;

        while (j < n) {
            mp[s[j] - 'a']++;

            while (mp[s[j] - 'a'] > 1) {

                mp[s[i] - 'a']--;
                i++;
            }

            len = max(len, j - i + 1);

            j++;
        }

        return len;
    }
};