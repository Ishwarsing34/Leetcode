class Solution {
    void generate(vector<vector<int>>& ans, vector<int>& nums, int ind, int n) {

        if (ind == n) {
            ans.push_back(nums);
            return;
        }

        for (int i = ind; i < n; i++) {

            swap(nums[ind], nums[i]);
            generate(ans, nums, ind + 1, n);
            swap(nums[ind], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        int n = nums.size();

        generate(ans, nums, 0, n);

        return ans;
    }
};