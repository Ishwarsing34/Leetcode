class Solution {
public:
    bool search(vector<int>& nums, int k) {

        int n = nums.size();

        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == k)
                return true;

            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            if (nums[low] <= nums[mid]) {

                if (nums[low] <= k && nums[mid] >= k) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {

                if (nums[mid] <= k && nums[high] >= k) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }


        return false;
    }
};