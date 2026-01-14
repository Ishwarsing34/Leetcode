class Solution {
    int count = 0;

    void solve(vector<int>& nums, int ind, int k,
               unordered_map<int, int>& mp) {

        if (ind == nums.size()) {
            count++;   // counts one valid subset (possibly empty)
            return;
        }

        // 🔹 Option 1: NOT pick nums[ind]
        solve(nums, ind + 1, k, mp);

        // 🔹 Option 2: pick nums[ind] (only if valid)
        if (mp[nums[ind] - k] == 0 && mp[nums[ind] + k] == 0) {
            mp[nums[ind]]++;
            solve(nums, ind + 1, k, mp);
            mp[nums[ind]]--;   // backtrack
        }
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        solve(nums, 0, k, mp);

        return count - 1;  // remove empty subset
    }
};
