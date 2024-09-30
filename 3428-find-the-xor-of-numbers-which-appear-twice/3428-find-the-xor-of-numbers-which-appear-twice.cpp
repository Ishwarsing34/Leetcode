class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> mp;
        // vector<int> ans;
        int result = 0;

        
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        
        for (auto &res : mp) {
            if (res.second == 2) {
               result ^= res.first;
            }
        }

    
        // for (int i = 0; i < ans.size(); i++) {
        //     result ^= ans[i];
        // }

        return result;
    }
};
