class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int, int> mp;

        int sum = 0;

        mp[0] = 1;

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0)
                sum += 1;
            else
                sum += 0;

            // if (sum % k == 0)
            //     cnt++;

            if (mp.find(sum - k) != mp.end()) {
                cnt += mp[sum - k];
            }

            mp[sum]++;
        }

        return cnt;
    }
};