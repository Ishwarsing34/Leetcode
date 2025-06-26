class Solution {
    int findxth(map<int, int>& mp, int x) {
        int cnt = 0;
        int ans = 0;

        for (auto i : mp) {
            cnt += i.second;

            if (cnt >= x) {
                ans = i.first;
                break;
            }
        }

        return ans;
    }

public:
    vector<int> getSubarrayBeauty(vector<int>& s, int k, int x) {

        map<int, int> mp;

        int n = s.size();

        int i = 0, j = 0;
        vector<int>res;

        while (j < n) {
            if (s[j] < 0) mp[s[j]]++;

            while (j - i + 1 == k) {
                int el = findxth(mp, x);
                res.push_back(el);
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(mp[s[i]]);
                }
                i++;
            }

            j++;
        }

        return res;
    }
};