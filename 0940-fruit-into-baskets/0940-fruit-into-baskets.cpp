class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        // set<int> st;

        int right = 0;
        int left = 0;
        int maxLen = 0;
        unordered_map<int, int> mp;

        for (right = 0; right < n; right++) {
            mp[fruits[right]]++;

            while (mp.size() > 2) {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }
                left++;
            }

            maxLen = max(right - left + 1, maxLen);
        }

        return maxLen;
    }
};