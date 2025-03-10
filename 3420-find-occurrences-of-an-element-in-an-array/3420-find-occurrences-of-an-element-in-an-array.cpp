class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
                                     int x) {
        vector<int> occurs;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                occurs.push_back(i);
            }
        }

        vector<int> ans;
        for (auto que : queries) {

            if (que <= occurs.size()) {
                ans.push_back(occurs[que - 1]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};