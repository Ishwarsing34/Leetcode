class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int right = 0;
        int left = 0;

        int mini = INT_MAX;
        int sum = 0;

        for(int right = 0; right < n; right++)
        {
              sum += nums[right];

              while(sum >= target)
              {
                  mini = min(right-left+1,mini);
                  sum -= nums[left];
                  left++;
              }
        }

        return mini == INT_MAX ? 0 : mini;
    }
};