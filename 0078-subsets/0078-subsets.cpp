class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int sub = 1 << n;  // Total number of subsets is 2^n
        vector<vector<int>> ans;

        for (int i = 0; i < sub; i++) { 
            vector<int> ls;
            for (int j = 0; j < n; j++) {  
                if (i & (1 << j)) {  
                    ls.push_back(nums[j]);
                }
            }
            ans.push_back(ls);  
        }

        return ans;
    }
};
