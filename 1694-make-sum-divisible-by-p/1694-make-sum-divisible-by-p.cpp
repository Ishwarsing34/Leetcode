class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        int n = nums.size();

        unordered_map<int, int> mp;
        long long totalsum = 0;

        for (int n : nums) {
            totalsum += n;
        }

        int rem = totalsum % p;

        int minlen = nums.size();

        if (rem == 0)
            return 0;

        mp[0] = -1;

        long long prefsum = 0;

        for (int i = 0; i < n; i++) {
            prefsum += nums[i];

            int curr_mod = prefsum % p;
            int target_mod = (curr_mod - rem + p) % p;

            if (mp.find(target_mod) != mp.end()) {
                minlen = min(minlen, i - mp[target_mod]);
            }

            mp[curr_mod] = i;
        }

        return minlen == nums.size() ? -1 : minlen;
    }
};