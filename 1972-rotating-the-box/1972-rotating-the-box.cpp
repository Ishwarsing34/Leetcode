class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        int n = box.size();
        int m = box[0].size();

        vector<vector<char>> res(m, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[j][i] = box[i][j];
            }
        }

        for (vector<char>& row : res) {
            reverse(begin(row), end(row));
        }

        for (int j = 0; j < n; j++) {
            for (int i = m - 1; i >= 0; i--) {
                if (res[i][j] == '.') {
                    int stoneRow = -1;

                    for (int k = i - 1; k >= 0; k--) {
                        if (res[k][j] == '*') {
                            break;
                        } else if (res[k][j] == '#') {
                            stoneRow = k;
                        }
                    }

                    if (stoneRow != -1) {
                        res[i][j] = '#';
                        res[stoneRow][j] = '.';
                    }
                }
            }
        }

        return res;
    }
};