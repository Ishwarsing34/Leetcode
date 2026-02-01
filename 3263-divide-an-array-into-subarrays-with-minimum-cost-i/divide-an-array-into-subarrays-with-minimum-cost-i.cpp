class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int maxSum = INT_MAX;

        for (int i = 1; i <= n-2; i++) {

            int sum = 0;

            for (int j = i + 1; j <= n-1; j++) {

                sum = nums[0] + nums[i] + nums[j];
                 maxSum = min(sum, maxSum);
            }

           
        }


        return maxSum;
    }
};