class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int, int> mp;

        int sum = 0;

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (sum == k)
                cnt++;

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