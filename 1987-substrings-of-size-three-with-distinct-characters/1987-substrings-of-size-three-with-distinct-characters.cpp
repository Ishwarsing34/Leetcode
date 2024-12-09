class Solution {

    bool isgood(string s) {
        if (s.size() < 3)
            return false;
        set<int> st;
        for (auto i : s) {
            st.insert(i);
        }

        return st.size() == 3;
    }

public:
    int countGoodSubstrings(string s) {
        if (s.size() < 3)
            return false;
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i <= n - 3; i++) {
            if (isgood(s.substr(i, 3))) {
                cnt++;
            }
        }

        return cnt;
    }
};