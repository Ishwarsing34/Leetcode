class Solution {
    void solve(int ind, vector<int>& arr, vector<vector<int>>&ans, int target,
               vector<int>temp) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = ind; i < arr.size(); i++) {

            if (i > ind && arr[i] == arr[i - 1])
                continue;

            if (arr[i] > target)
                break;

            temp.push_back(arr[i]);
            solve(i + 1, arr, ans, target - arr[i], temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {

        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());
        vector<int> temp;
        solve(0, arr, ans, target, temp);

        return ans;
    }
};