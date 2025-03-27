class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        if (m * n != original.size())
            return {};

        vector<vector<int>> matrix(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {

                matrix[row][col] = original[row * n + col];
            }
        }

        return matrix;
    }
};