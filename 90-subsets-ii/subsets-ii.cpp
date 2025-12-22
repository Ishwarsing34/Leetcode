class Solution {
    void solve(vector<int> nums, vector<vector<int>>& ans, vector<int> temp,
               int ind, int n) {
        ans.push_back(temp);

        for (int i = ind; i < n; i++) {

            if (i > ind && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);
            solve(nums, ans, temp, i + 1, n);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;

        vector<int> temp;

        sort(nums.begin(), nums.end());

        solve(nums, ans, temp, 0, nums.size());

        return ans;
    }
};