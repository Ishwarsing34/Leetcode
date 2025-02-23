class Solution {
    bool check(string s) {
        set<int> st;

        if (s.size() < 3)
            return false;

        for (auto i : s) {
            st.insert(i);
        }

        return st.size() == 3;
    }

public:
    int countGoodSubstrings(string s) {

        int cnt = 0;
        int n = s.size();

        for (int i = 0; i <= n - 3; i++) {
            if (check(s.substr(i, 3))) { 
                cnt++;
            }
        }

        return cnt;
    }
};