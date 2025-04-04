class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {

        int n = nums.size();

        int low = 0;
        int high = n - 1;
        int index = -1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1]) {

                low = mid + 1;
            } else {
                index = mid;
                high = mid;
            }
        }

        return index;
    }
};