class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int left = 0;

        vector<int> greater;
        vector<int> equal;
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                result[left] = nums[i];
                left++;

            } else if (nums[i] > pivot) {
                greater.push_back(nums[i]);
            } else {
                equal.push_back(nums[i]);
            }
        }

        

        for (auto nums : equal) {
            result[left] = nums;
            left++;
        }

        for (auto num : greater) {
            result[left] = num;
            left++;
        }

        return result;
    }
};