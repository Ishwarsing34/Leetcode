class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        multiset<int> st;

        int i = 0;
        int j = 0;
        int maxLen = 0;

        while (j < n) {

            st.insert(nums[j]);

            while (*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[i]));
                i++;
            }

            maxLen = max(j - i + 1, maxLen);
            j++;
        }

        return maxLen;
    }
};