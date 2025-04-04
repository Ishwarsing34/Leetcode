class Solution {

    bool Find(vector<int>& nums, int mid, int n, int thresh) {

        int sum = 0;
        ;

        for (int i = 0; i < n; i++) {

            int div = (nums[i] + mid - 1) / mid;

            sum += div;

            if (sum > thresh)
                return false;
        }
        return sum<=thresh;
    }

public:
    int smallestDivisor(vector<int>& nums, int thresh) {

        int n = nums.size();

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (Find(nums, mid, n, thresh)) {

                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};