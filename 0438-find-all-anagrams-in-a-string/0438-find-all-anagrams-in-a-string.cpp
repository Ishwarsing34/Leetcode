class Solution {
    bool allzero(vector<int>& counter) {

        for (auto i : counter) {
            if (i != 0)
                return false;
        }

        return true;
    }

public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        vector<int>counter(26, 0);

        for (int i = 0; i < p.size(); i++) {
            counter[p[i] - 'a']++;
        }

        int j = 0;
        int i = 0;
        vector<int> result;

        int k = p.size();

        while (j < n) {
            counter[s[j] - 'a']--;

            if (j - i + 1 == k) {
                if (allzero(counter)) {
                    result.push_back(i);
                }

                counter[s[i] - 'a']++;
                i++;
            }

            j++;
        }

        return result;
    }
};