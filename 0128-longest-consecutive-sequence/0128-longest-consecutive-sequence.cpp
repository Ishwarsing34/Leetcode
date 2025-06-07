class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int n = nums.size();
        int last_smll = INT_MIN;
        int cnt = 0;
        int longest = 1;

        sort(nums.begin(),nums.end());

        for (int i = 0; i < n; i++) {
            if (nums[i]-1 == last_smll){
                    cnt += 1;
                    last_smll = nums[i];
                }
            else if (last_smll != nums[i]) {
                cnt = 1;
                last_smll = nums[i];
            }

            longest = max(longest, cnt);
        }

        return longest;
    }
};