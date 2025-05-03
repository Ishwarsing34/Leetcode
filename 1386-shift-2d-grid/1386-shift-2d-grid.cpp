class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int> flatten;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                flatten.push_back(grid[i][j]);
            }
        }

        vector<int> ans(flatten.size());

        for (int i = 0; i < flatten.size(); i++) {
            ans[(i + k) % (n * m)] = flatten[i];
        }

        
        
        vector<vector<int>>result(n,vector<int>(m));

        for(int i=0;i<n*m;i++){
            result[i/m][i%m] = ans[i];
        }

        return result;
    }
};
