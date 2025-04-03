class Solution {
public:
    char nextGreatestLetter(vector<char>& nums, char target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        char ans = nums[low];

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] > target) {
                ans = nums[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};