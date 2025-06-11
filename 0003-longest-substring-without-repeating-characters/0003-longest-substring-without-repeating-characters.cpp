class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int i = 0, j = 0;

        int longest = 0;

        int n = s.size();

        while (j < n) {

            mp[s[j] - 'a']++;

            while (mp[s[j] - 'a'] > 1) {

                mp[s[i] - 'a']--;
                i++;
            }

            longest = max(j - i + 1, longest);
            j++;
        }

        return longest;
    }
};