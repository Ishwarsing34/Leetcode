class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>x,y;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }

        //setting the rows to zero

        for(int i=0;i<x.size();i++){
            int ind = x[i];
            for(int j=0;j<m;j++){
                matrix[ind][j] = 0;
            }
        }


        for(int i=0;i<y.size();i++){
            int ind = y[i];
            for(int j=0;j<n;j++){
                matrix[j][ind] = 0;
            }
        }
    }
};