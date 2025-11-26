class Solution {

    int atmost(vector<int>& nums, int goal) {

        int n = nums.size();


        if(goal < 0) return 0;

        int i = 0, j = 0;

        int sum = 0;
        int cnt = 0;

        while (j < n) {

            sum += nums[j];

            while (sum > goal) {
                sum -= nums[i];
                i++;
            }

            cnt += (j - i + 1);
            j++;
        }

        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};