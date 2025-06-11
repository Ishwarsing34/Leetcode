class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        int j = 0, i = 0;
        int longest = 0;

        while (j < n) {
            if (nums[j] == 0)
                k--;

            while (k < 0) {

                if (nums[i] == 0)
                    k++;

                i++;
            }

            longest = max(longest, j - i + 1);
            j++;
        }

        return longest;
    }
};