class Solution {
    int atmost(vector<int>& nums, int k) {

        int right = 0, left = 0, ans = 0;
        unordered_map<int,int>mp;

        for (right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;

            while (mp.size() > k) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }

            ans+=right - left + 1;
        }

        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return atmost(nums, k) - atmost(nums, k - 1);
    }
};