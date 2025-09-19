class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans;

        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (int i = 0; i < n; i++) {
            int adj1 = nums[i] + 1;
            int adj2 = nums[i] - 1;

            int isFound = true;

            int NumFreq = mp[nums[i]];

            if (mp.find(adj1) != mp.end() || mp.find(adj2) != mp.end() || NumFreq > 1) {
                isFound = false;
            }

         

            if (isFound) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};