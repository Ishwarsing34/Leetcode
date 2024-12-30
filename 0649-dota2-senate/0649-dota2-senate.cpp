class Solution {
    bool RemoveSenate(string senate, char ch, int idx) {
         int n = senate.size();
        for (int i = 0; i < n; i++) {
             int pos = (idx + i) % n;
            if (senate[pos] == ch) {
               
                senate.erase(begin(senate) + pos);
                if (pos < idx) {
                    idx--;
                }

                return pos < idx;
            }
        }

        return false;
    }

public:
    string predictPartyVictory(string senate) {
        int n = senate.size();

        int R_cnt = count(begin(senate), end(senate), 'R');
        int D_cnt = n - R_cnt;

        int idx = 0;

        while (R_cnt > 0 && D_cnt > 0) {
            if (senate[idx] == 'R') {
                RemoveSenate(senate, 'D', idx);
                D_cnt--;
            } else {

                RemoveSenate(senate, 'R', idx);
                 R_cnt--;
            }

            idx = (idx + 1)%senate.size();
        }

        return R_cnt == 0 ? "Dire" : "Radiant";
    }
};