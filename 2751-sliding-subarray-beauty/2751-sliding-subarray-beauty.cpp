class Solution {
    int find(map<int, int> &mp, int x) {

        int cnt = 0, ans = 0;

        for (auto i : mp) {

            cnt += i.second;

            if (cnt >= x) {
                ans = i.first;
                break;
            }
        }

        return ans;
    }

public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        map<int, int> mp;
        vector<int> res;

        int i = 0, j = 0;

        while (j < n) {

            if (nums[j] < 0) {
                mp[nums[j]]++;
            }

            if(j - i + 1 == k) {

                int el = find(mp, x);
                res.push_back(el);

                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            j++;
        }
        return res;
    }
};