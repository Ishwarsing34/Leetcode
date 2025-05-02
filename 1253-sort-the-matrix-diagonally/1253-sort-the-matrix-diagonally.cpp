class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[i - j].push_back(matrix[i][j]);
            }
        }
        for (auto& [k, vec] : mp) {
            sort(vec.begin(), vec.end());
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                matrix[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }

        return matrix;
    }
};