class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char, int> mp;

        int maxi = 0;

        int i = 0, j = 0;

        while (j < n) {
            mp[s[j] - 'a']++;

            while (mp[s[j] - 'a'] > 1) {
                mp[s[i] - 'a']--;
                i++;
            }

            maxi = max(j - i + 1, maxi);
            j++;
        }

        return maxi;
    }
};