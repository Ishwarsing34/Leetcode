class Solution {
    int findMin(vector<int>& nums) {

        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return high;
    }

    int BinarySearch(int l, int r, vector<int>& nums, int target) {

        int ind = -1;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                ind = mid;
                break;
            } else if (nums[mid] > target) {
                r = mid - 1;
            }

            else {
                l = mid + 1;
            }
        }

        return ind;
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int idx = -1;

        int pivotIdx = findMin(nums);

         idx = BinarySearch(0, pivotIdx - 1, nums, target);

        if (idx != -1)
            return idx;

         idx = BinarySearch(pivotIdx, n - 1, nums, target);

        return idx;
    }
};