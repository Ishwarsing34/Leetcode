class Solution {



    void find(int row, int n,  vector<vector<string>>&ans, vector<string>&Board, vector<bool>column, vector<bool>&left, vector<bool>&right)
    {
        //base 
        if(row == n){
            ans.push_back(Board);
            return;
        }
        //putting queen at any n position

        for(int j=0;j<n;j++)
        {
            if(column[j] == 0 && left[n-1+j-row] == 0 && right[row+j] == 0){
                 column[j] = 1;
                 left[n-1+j-row] = 1;
                 right[row+j] = 1;
                 Board[row][j] = 'Q';
                 find(row+1,n,ans,Board,column,left,right);
                 column[j] = 0;
                 Board[row][j] = '.';
                  left[n-1+j-row] = 0;
                 right[row+j] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
       //optimize
        vector<vector<string>>ans;
        vector<string>Board(n);

        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        Board[i].push_back('.');

        vector<bool>column(n,0);

        vector<bool>left(2*n-1,0);
        vector<bool>right(2*n-1,0);
        
        find(0,n,ans,Board,column,left,right);


        return ans;



    }
};