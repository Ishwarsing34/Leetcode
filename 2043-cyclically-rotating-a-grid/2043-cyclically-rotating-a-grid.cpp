class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        int startrow =0;
        int startcol =0;
        int endcol = m-1;
        int endrow = n-1;

    while(startrow<endrow && startcol<endcol){
        vector<int>temp;

        // right
        for(int i=startcol;i<=endcol;i++){
            temp.push_back(grid[startrow][i]);
        }
        
        // down
        for(int i =startrow+1;i<=endrow;i++){
            temp.push_back(grid[i][endcol]);
        }

        // left
        for(int i = endcol-1;i>=startcol;i--){
            temp.push_back(grid[endrow][i]);
        }
        
        // up
        for(int i = endrow-1;i>=startrow+1;i--){
            temp.push_back(grid[i][startcol]);
        }

        // pushing rotated value of grid from k
        int ind =0;

        // right
        for(int i=startcol;i<=endcol;i++){
            grid[startrow][i] = temp[(ind+k)%temp.size()];
            ind++;
        }
        
        // down
        for(int i =startrow+1;i<=endrow;i++){
            grid[i][endcol]= temp[(ind+k)%temp.size()];
            ind++;
        }

        // left
        for(int i = endcol-1;i>=startcol;i--){
            grid[endrow][i] = temp[(ind+k)%temp.size()];
            ind++; 
        }
        
        // up
        for(int i = endrow-1;i>=startrow+1;i--){
            grid[i][startcol] = temp[(ind+k)%temp.size()];
            ind++;
        }


        startrow++;
        startcol++;
        endrow--;
        endcol--;
    }
    return grid;
    }
};