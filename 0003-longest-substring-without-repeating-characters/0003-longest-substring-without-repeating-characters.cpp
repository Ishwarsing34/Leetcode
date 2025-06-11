class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();

        int right = 0, left = 0;

        unordered_map<int, int> lastSeen;
        int longest = 0;

        for (int right = 0; right < n; right++) {
            char c = s[right];

                if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }

            lastSeen[c] = right;
            longest = max(right - left + 1, longest);
        }

        return longest;
    }
};