class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> copy(n, vector<int>(m));

        copy = mat;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                copy[i][(j + k) % m] = mat[i][j];
            }
        }

        return copy == mat;
    }
};