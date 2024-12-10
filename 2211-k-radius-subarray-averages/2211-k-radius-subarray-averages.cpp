class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n, -1);

        if (k == 0)
            return nums;

        if (n < 2 * k + 1)
            return result;

        vector<long long> pref(n, 0);
        pref[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }

        for (int i = k; i <= n - k - 1; i++) {
            int left_idx = i - k;
            int right_idx = i + k;

            long long sum = pref[right_idx];

            if (left_idx > 0) {
                sum -= pref[left_idx - 1];
            }

            result[i] = sum/(2 * k + 1);
        }

        return result;
    }
};