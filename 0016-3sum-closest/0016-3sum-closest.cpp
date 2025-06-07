class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closesum = INT_MAX ;

        for (int i = 0; i < n; i++) {
            int s = i + 1;
            int e = n - 1;

            while (s < e) {

                int sum = nums[i] + nums[s] + nums[e];

                if (abs(target - sum) < abs( 1LL *target - closesum)) {
                    closesum = sum;
                } else if (sum < target)
                    s++;
                else
                    e--;
            }
        }

        return closesum;
    }
};