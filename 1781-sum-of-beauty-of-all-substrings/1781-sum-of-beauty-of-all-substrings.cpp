class Solution {
public:
    int beautySum(string s) {

        int n = s.size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                int maxi = INT_MIN;
                int mini = INT_MAX;

                mp[s[j]]++;

                for (auto i : mp) {
                    maxi = max(i.second, maxi);
                    mini = min(i.second, mini);
                }

                ans += (maxi - mini);
            }
        }

        return ans;
    }
};