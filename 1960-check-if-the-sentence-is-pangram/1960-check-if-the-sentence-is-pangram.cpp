class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> ans(26, 0);
        int cnt = 0;
        for (auto it : sentence) {

            int idx = it - 'a';

            if (ans[idx] == 0) {
                ans[idx]++;
                cnt++;
            }
        }

        return cnt == 26 ? true : false;
    }
};