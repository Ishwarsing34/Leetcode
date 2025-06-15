class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

        vector<vector<int>> res;

        map<int, vector<int>> mp;  // Change 1: store all indices per group size

        int n = groupSizes.size();

        for (int i = 0; i < n; i++) {
            mp[groupSizes[i]].push_back(i);  // Change 2: push_back, don't overwrite
        }

        vector<bool> visited(n, 0);

        for (auto it : mp) {
            int m = it.first;
            vector<int> indices = it.second;

            vector<int> ans;
            for (int i = 0; i < indices.size(); i++) {
                if (visited[indices[i]] == 0) {
                    ans.push_back(indices[i]);
                    visited[indices[i]] = 1;
                }

                if (ans.size() == m) {
                    res.push_back(ans);
                    ans.clear();
                }
            }
        }

        return res;
    }
};
