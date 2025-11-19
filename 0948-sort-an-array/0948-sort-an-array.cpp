class Solution {

private:
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;

        int i = low;
        int j = mid + 1;

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid)
            temp.push_back(nums[i++]);
        while (j <= high)
            temp.push_back(nums[j++]);

        int n = temp.size();

        for (int i = 0; i < n; i++) {
            nums[low + i] = temp[i];
        }
    }

    void mS(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;

        mS(nums, low, mid);
        mS(nums, mid + 1, high);

        merge(nums, low, mid, high);
    }

public:
    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        mS(nums, 0, n - 1);

        return nums;
    }
};