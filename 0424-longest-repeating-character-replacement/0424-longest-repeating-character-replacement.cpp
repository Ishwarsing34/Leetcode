class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();

        unordered_map<char, int> mp;

        int i = 0, j = 0;

        int longest = 0;
        int maxFreq = 0;

        while (j < n) {

            mp[s[j]]++;

            maxFreq = max(mp[s[j]], maxFreq);

            while (j - i + 1 - maxFreq > k) {
                mp[s[i]]--;
                i++;
            }
            
            longest = max(j - i + 1, longest);
            j++;
            
        }

        return longest;
    }
};