class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int right = 0, left = 0, ans = 0;
        int hash[26] = {};

        for (right = 0; right < n; right++) {
            hash[s[right] - 'A']++;

            while (right - left + 1 - *max_element(hash, hash + 26) > k) {
                hash[s[left] - 'A']--;
                left++;
            }

            ans = max(right - left + 1, ans);
        }

        return ans;
    }
};