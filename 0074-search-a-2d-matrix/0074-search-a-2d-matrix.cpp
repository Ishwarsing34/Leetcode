class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = n*m-1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            int r = mid/m , c = mid%m;

            if(mat[r][c] == target) return true;
            else if(mat[r][c] < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};