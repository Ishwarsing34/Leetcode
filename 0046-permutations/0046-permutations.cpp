class Solution {
    void permutation(vector<int>& nums, vector<vector<int>>& ans, int index) {

        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            swap(nums[i], nums[index]);
            permutation(nums, ans, index + 1);
            swap(nums[i], nums[index]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        // using without extra spaxce

        vector<vector<int>> ans;

        permutation(nums, ans, 0);

        return ans;
    }
};