class Solution {
    bool getSum(vector<int>& nums, int mid, int threshold) {
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Use integer arithmetic for ceiling
            long long div = (nums[i] + mid - 1) / mid;
            sum += div;
        }

        return sum <= threshold;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end()); // Max element as the upper bound
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (getSum(nums, mid, threshold)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};
