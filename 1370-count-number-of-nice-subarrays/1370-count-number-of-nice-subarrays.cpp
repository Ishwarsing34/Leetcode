class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        mp[0] = 1;
        int sum = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] % 2 != 0) {
                sum += 1;
            } else {
                sum += 0;
            }

            if (mp.find(sum - k) != mp.end()) {
                cnt += mp[sum - k];
            }

            if (mp.find(sum) == mp.end()) {
                mp[sum] = 1;
            } else {
                mp[sum]++;
            }
        }

        return cnt;
    }
};