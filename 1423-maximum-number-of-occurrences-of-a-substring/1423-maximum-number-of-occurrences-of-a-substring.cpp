class Solution {
public:
    int maxFreq(string s, int maxLet, int minSize, int maxSize) {
        int n = s.size();
        unordered_map<string, int> substringCount; // To count occurrences of substrings
        int maxFrequency = 0;

        for (int i = 0; i <= n - minSize; i++) {
            unordered_map<char, int> charCount; // To track character frequencies in the substring
            int uniqueCount = 0;

            for (int j = i; j < i + minSize; j++) {
                if (charCount[s[j]]++ == 0) { // Increment character count and track unique characters
                    uniqueCount++;
                }
            }

            // Check if the substring meets the unique character constraint
            if (uniqueCount <= maxLet) {
                string substring = s.substr(i, minSize); // Extract substring
                maxFrequency = max(maxFrequency, ++substringCount[substring]);
            }
        }

        return maxFrequency;
    }
};
