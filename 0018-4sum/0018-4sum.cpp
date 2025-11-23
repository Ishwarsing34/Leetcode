class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {

                int k = j + 1, l = n - 1;

                while (k < l) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                        while (k < l && nums[k] == nums[k + 1])
                            k++;

                        while (k < l && nums[l] == nums[l - 1])
                            l--;

                        k++, l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }

                while (j + 1 < n && nums[j] == nums[j + 1])
                    j++;
            }

            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }

        return ans;
    }
};