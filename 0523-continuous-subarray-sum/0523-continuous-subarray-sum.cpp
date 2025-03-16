class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        mp[0] = -1;

        int cnt = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int rem = sum % k;

                      if (rem < 0) {
                rem = rem + k;
            }

            if (mp.find(rem) != mp.end()) {

                if (i - mp[rem] >= 2) {
                    return true;
                }
            }

            if (mp.find(rem) == mp.end()) {
                mp[rem] = i;
            }
        }

        return false;
    }
};