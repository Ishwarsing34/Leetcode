class Solution {
    bool check(vector<string>& curr) {

        string top = curr[0];
        string left = curr[1];
        string right = curr[2];
        string bottom = curr[3];

        if (top[0] == left[0] && top[3] == right[0] && bottom[0] == left[3] &&
            bottom[3] == right[3])
            return true;

        else
            return false;
    }
    void generate(vector<string>& words, vector<vector<string>>& ans,
                  vector<bool>& used, vector<string>& curr) {

        if (curr.size() == 4) {

            if (check(curr)) {
                ans.push_back(curr);
            }

            return;
        }

        for (int i = 0; i < words.size(); i++) {

            if (used[i])
                continue;

            used[i] = true;
            curr.push_back(words[i]);

            generate(words, ans, used, curr);

            curr.pop_back();

            used[i] = false;
        }
    }

public:
    vector<vector<string>> wordSquares(vector<string>& words) {

        vector<vector<string>> ans;

        int n = words.size();
        vector<string> curr;
        vector<bool> used(n, false);

        generate(words, ans, used, curr);

        sort(ans.begin(), ans.end());

        return ans;
    }
};