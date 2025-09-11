class Solution {
public:
    long long minimumRemoval(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long long> pref(n), suff(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + nums[i];

        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) suff[i] = suff[i + 1] + nums[i];

        long long mincnt = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long prevSum = i == 0 ? 0 : pref[i - 1];
            long long aheadSum = suff[i] - (long long)nums[i] * (n - i);
            mincnt = min(mincnt, prevSum + aheadSum);
        }

        return mincnt;
    }
};
