class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {

            sum += nums[i];
            if (sum == goal)
                cnt++;

            if (mp.find(sum-goal) != mp.end()) {
                cnt = mp[sum - goal] + cnt;
            }

            if (mp.find(sum) != mp.end()) {
                mp[sum]++;
            } else {
                mp[sum] = 1;
            }
        }

        return cnt;
    }
};