class Solution {
    int atmost(vector<int>& nums, int goal) {

        long long right = 0, left = 0, sum = 0, ans = 0;
        for (right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while (left <= right and sum > goal) {
                sum -= nums[left];
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // general sliding window will fail here
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};