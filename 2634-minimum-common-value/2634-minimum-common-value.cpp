class Solution {

    int checkCom(vector<int>& nums1, int num) {

        int n = nums1.size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums1[mid] == num)
                return true;
            else if (nums1[mid] < num)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }

public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        for (int num : nums2) {

            if (checkCom(nums1, num)) {
                return num;
            }
        }

        return -1;
    }
};