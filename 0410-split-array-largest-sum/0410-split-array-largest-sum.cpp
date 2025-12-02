class Solution {

    int isPossible(vector<int>& nums, int mid, int k) {
        int cnt = 1;
        int partition = 0;

        for (int i = 0; i < nums.size(); i++) {
            partition += nums[i];

            if (partition > mid) {
                partition = nums[i];
                cnt++;
            }
        }

        return cnt;
    }

public:
    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int partitions = isPossible(nums, mid, k);

            if (partitions <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};