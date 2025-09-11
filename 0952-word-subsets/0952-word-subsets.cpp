class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0);

        // Build the maximum required frequency from words2
        for (string &w : words2) {
            vector<int> freq(26, 0);
            for (char c : w) freq[c - 'a']++;
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        vector<string> ans;
        // Check each word in words1
        for (string &w : words1) {
            vector<int> freq(26, 0);
            for (char c : w) freq[c - 'a']++;

            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans.push_back(w);
        }

        return ans;
    }
};
