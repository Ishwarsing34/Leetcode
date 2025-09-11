class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<int> maxfreq(26, 0);

        vector<string> ans;
        for (string& w : words2) {
            vector<int> freq(26, 0);

            for (auto c : w) {
                freq[c - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                maxfreq[i] = max(maxfreq[i], freq[i]);
            }
        }

        for (string& w : words1) {

            vector<int> freq(26, 0);

            for (char c : w) {
                freq[c - 'a']++;
            }

            bool ok = true;

            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxfreq[i]) {
                    ok = false;
                    break;
                }
            }

            if ((ok))
                ans.push_back(w);
        }

        return ans;
    }
};