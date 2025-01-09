class Solution {

    int findMin(vector<int>& nums,int low, int high) {

        int n = nums.size();

        

        while (low < high) {

            while (low < high && nums[low] == nums[low + 1]) {
                low++;
            }

            while (low < high && nums[high] == nums[high - 1]) {
                high--;
            }

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
    bool search(vector<int>& nums, int target) {

        int n = nums.size();

        int low = 0;
        int high = n - 1;

        int idx = -1;

        int pivotIdx = findMin(nums, low, high);

        idx = BinarySearch(0, pivotIdx - 1, nums, target);

        if(idx != -1) return true;

        idx = BinarySearch(pivotIdx, n - 1, nums, target);

        return idx == -1 ? false : true;
    }
};