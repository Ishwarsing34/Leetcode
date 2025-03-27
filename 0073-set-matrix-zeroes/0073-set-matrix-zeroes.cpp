class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> x, y;

        // Step 1: Store the row and column indices of zeroes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }

        // Step 2: Set the entire row to zero
        for (int i = 0; i < x.size(); i++) {
            int ind = x[i];
            for (int j = 0; j < m; j++) {  // ✅ Loop through columns
                matrix[ind][j] = 0;
            }
        }

        // Step 3: Set the entire column to zero
        for (int i = 0; i < y.size(); i++) {
            int ind = y[i];
            for (int j = 0; j < n; j++) {  // ✅ Loop through rows
                matrix[j][ind] = 0;
            }
        }
    }
};
