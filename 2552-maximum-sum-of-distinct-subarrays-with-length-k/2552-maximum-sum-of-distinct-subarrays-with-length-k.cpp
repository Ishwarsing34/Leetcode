class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long curr_sum = 0;
        long long result = 0;
        int n = nums.size();

        unordered_set<int> st;
        int i = 0;
        int j = 0;
        while (j < n) {
            while (st.count(nums[j])) {
                curr_sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            curr_sum += nums[j];
            st.insert(nums[j]);

            if (j - i + 1 == k) {
                result = max(result, curr_sum);
                curr_sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            j++;
        }

        return result;
    }
};