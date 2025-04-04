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

        int low = l;
        int high = r;

        int ind = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ind = mid;
                break;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ind;
    }

public:
    int search(vector<int>& nums, int target) {

        int pivotInd = findMin(nums);

        int n = nums.size();

        int idx = -1;

        idx = BinarySearch(0, pivotInd - 1, nums, target);

        if (idx != -1)
            return idx;

        idx = BinarySearch(pivotInd, n - 1, nums, target);

        return idx;
    }
};