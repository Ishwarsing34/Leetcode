class Solution {
    bool checkallzero(vector<int>& counter) {

        for (auto i : counter) {
            if (i != 0)
                return false;
        }

        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> counter(26, 0);
        int k = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            char ch = s1[i];
            counter[ch - 'a']++;
        }

        while (j < m) {
            counter[s2[j] - 'a']--;

            if (j - k + 1 == n) {
                if (checkallzero(counter)) {
                    return true;
                }

                counter[s2[k] - 'a']++;
                k++;
            }
            j++;
        }

        return false;
    }
};