class Solution {

    void solve(int& cnt, vector<int>& nums, int ind) {

        if (ind == nums.size()) {

            cnt++;
            return;
        }

        int pos = ind + 1;

        for (int i = ind; i < nums.size(); i++) {

            if (nums[i] % pos != 0 && pos % nums[i] != 0)
                continue;
            else {

                swap(nums[ind], nums[i]);

                solve(cnt, nums, ind + 1);

                swap(nums[ind], nums[i]);
            }
        }
    }

public:
    int countArrangement(int n) {

        int cnt = 0;

        vector<int> nums;

        for (int i = 1; i <= n; i++) {

            nums.push_back(i);
        }

        solve(cnt, nums, 0);

        return cnt;
    }
};