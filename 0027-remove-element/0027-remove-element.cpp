class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = 0;
        int n = nums.size();

        while (i != n) {
            if (nums[i] != val) {
                swap(nums[i],nums[j]);
                j++;
            }
            i++;
        }
        return j;
    }
};