class Solution {
    void solve(vector<vector<int>>& ans, vector<int>temp, int i, int n,vector<int>nums) {

        if (i == n) {
            ans.push_back(temp);
             return;
        }

        solve(ans, temp, i + 1, n,nums);
        temp.push_back(nums[i]);
        solve(ans, temp, i + 1, n,nums);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;

        vector<int> temp;

        int i = 0;
        int n = nums.size();

        solve(ans, temp, i, n,nums);

        return ans;
    }
};