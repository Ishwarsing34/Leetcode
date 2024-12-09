class Solution {
public:
    vector<int> arrayChange(vector<int>& nums,
                            vector<vector<int>>& operations) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        for (auto op : operations) {

            int idx = mp[op[0]];
            mp.erase(op[0]);
            mp[op[1]] = idx;
        }

        vector<int> ans(n, 0);
        for (auto it : mp) {
            ans[it.second] = it.first;
        }

        return ans;
    }
};