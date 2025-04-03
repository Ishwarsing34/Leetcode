class Solution {

    int checkGreater(vector<int>& nums, int x) {

        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] >= x) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return n - low;
    }

public:
    int specialArray(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(),nums.end());

        for (int x = 1; x <= n; x++) {
            int cnt = checkGreater(nums, x);
            if (cnt == x) {
                return x;
            }
        }
        return -1;
    }
};