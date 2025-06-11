class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size();

        int i = 0, j = 0;
        int B_cnt = 0;
        int min_op = INT_MAX;

        while (j < n) {
            if (s[j] == 'B') {
                B_cnt++;
            }

            while (j - i + 1 > k) {

                if (s[i] == 'B')
                    B_cnt--;
                i++;
            }

            if (j - i + 1 == k) {
                min_op = min( k - B_cnt, min_op);
            }

            j++;
        }

        return min_op;
    }
};