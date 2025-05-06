class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        
        vector<vector<int>> ans;

        // Step 1: Push all coordinates along with their distance from (rCenter, cCenter)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int distance = abs(i - rCenter) + abs(j - cCenter); // Manhattan Distance
                ans.push_back({i, j, distance});  // Store cell coordinates and distance
            }
        }

        // Step 2: Sort by the distance (the third element in each subarray)
        sort(ans.begin(), ans.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];  // Compare by distance
        });

        // Step 3: Extract only the coordinates and return
        vector<vector<int>> result;
        for (auto& cell : ans) {
            result.push_back({cell[0], cell[1]});
        }

        return result;
    }
};
