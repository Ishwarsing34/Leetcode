class Solution {
    void subseq(vector<int> nums, int ind, int n, vector<int> temp,
                vector<vector<int>>& ans) {

        if (ind == n) {
            ans.push_back(temp);
            return;
        }

        subseq(nums, ind + 1, n, temp, ans);
        temp.push_back(nums[ind]);
        subseq(nums, ind + 1, n, temp, ans);
        // temp.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> temp;
        vector<vector<int>> ans;

        int n = nums.size();

        subseq(nums, 0, n, temp, ans);

        return ans;
    }
};