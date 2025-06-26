class Solution {
    bool isallzeros(vector<int>& cnt) {

        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0)
                return false;
        }

        return true;
    }

public:
    vector<int> findAnagrams(string s, string p) {

        int n = s.size();
        int k = p.size();

        vector<int> ans;

        vector<int> cnt(26, 0);

        for (int i = 0; i < k; i++) {
            cnt[p[i] - 'a']++;
        }

        int j = 0, i = 0;

        while (j < n) {

            cnt[s[j] - 'a']--;

            while (j - i + 1 == k) {

                if (isallzeros(cnt)) {
                    ans.push_back(i);
                }
                cnt[s[i] - 'a']++;
                i++;
            }

            j++;
        }

        return ans;
    }
};