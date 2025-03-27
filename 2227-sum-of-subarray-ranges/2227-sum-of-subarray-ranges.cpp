class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;  

        for (int i = 0; i < n; i++) {
            int small = nums[i];
            int large = nums[i];

            for (int j = i; j < n; j++) {
                small = min(small, nums[j]);
                large = max(large, nums[j]);

                sum += (large - small);
            }
        }

        return sum;
    }
};
