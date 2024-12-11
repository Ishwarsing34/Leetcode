class Solution {
    int xthElement(map<int, int>& mp, int x) {

        int count = 0, xthEl = 0;
        for (auto it : mp) {
            count += it.second;
            if (count >= x) {
                xthEl = it.first;
                break;
            }
        }

        return xthEl;
    }

public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        map<int, int> mp;
        vector<int>ans;

        int i = 0;
        int j = 0;

        while (j < n) {

            if (nums[j] < 0) {
                mp[nums[j]]++;
            }

            if (j - i + 1 == k) {
                int ele = xthElement(mp, x);
                ans.push_back(ele);

                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                    
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};