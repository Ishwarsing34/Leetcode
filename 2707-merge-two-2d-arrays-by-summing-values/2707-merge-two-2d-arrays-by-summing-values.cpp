class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;

        int n = nums1.size();
        int m = nums2.size();

        int i = 0, j = 0;

        while (i < n && j < m) {
            if (nums1[i][0] == nums2[j][0]) {
                // Keys match, sum the second elements
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                ++i;
                ++j;
            } else if (nums1[i][0] < nums2[j][0]) {
                // Add the smaller key from nums1
                ans.push_back(nums1[i]);
                ++i;
            } else {
                // Add the smaller key from nums2
                ans.push_back(nums2[j]);
                ++j;
            }
        }

        // Add remaining elements from nums1
        while (i < n) {
            ans.push_back(nums1[i]);
            ++i;
        }

        // Add remaining elements from nums2
        while (j < m) {
            ans.push_back(nums2[j]);
            ++j;
        }

        return ans;
    }
};