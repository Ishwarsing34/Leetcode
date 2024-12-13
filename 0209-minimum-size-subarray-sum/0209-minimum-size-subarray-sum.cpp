class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int right = 0;
        int left = 0;
        int sum = 0;
        int len = INT_MAX;

        for (right = 0; right < n; right++) {
            sum += nums[right];

            while(sum >= target) {
                len = min(right - left + 1, len);
                sum -= nums[left];
                left++;
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};