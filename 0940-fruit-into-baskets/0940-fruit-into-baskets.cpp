class Solution {
public:
    int totalFruit(vector<int>& f) {

        int n = f.size();

        map<int, int> mp;
        int maxx = 0;
        int i = 0, j = 0;

        while (j < n) {
            mp[f[j]]++;

            while (mp.size() > 2) {
                if (mp.count(f[i])) {
                    mp[f[i]]--;
                }
                if (mp[f[i]] == 0) {
                    mp.erase(f[i]);
                }

                i++;
            }

            maxx = max(j - i + 1, maxx);
            j++;
        }

        return maxx;
    }
};