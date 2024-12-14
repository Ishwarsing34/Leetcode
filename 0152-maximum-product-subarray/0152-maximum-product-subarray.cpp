class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long pre = 1, suf = 1;
        long long ans = nums[0];
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            pre *= nums[i];
            suf *= nums[n - i - 1];

            ans = max(ans, max(pre, suf));

            if (pre == 0) pre = 1;
            if (suf == 0) suf = 1;

            // Reset the product if it becomes too large or too small
            if (pre > LLONG_MAX / 10 || pre < LLONG_MIN / 10) pre = 1;
            if (suf > LLONG_MAX / 10 || suf < LLONG_MIN / 10) suf = 1;
        }

        return ans;
    }
};
