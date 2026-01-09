class Solution {
    bool check(vector<vector<char>>& board, int sr, int er, int sc, int ec) {

        set<char> st;

        for (int i = sr; i <= er; i++) {
            for (int j = sc; j <= ec; j++) {

                if (board[i][j] == '.')
                    continue;

                if (st.find(board[i][j]) != st.end())
                    return false;
                else
                    st.insert(board[i][j]);
            }
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        // check rows
        for (int i = 0; i < n; i++) {
            set<char> st;
            for (int j = 0; j < m; j++) {

                if (board[i][j] == '.')
                    continue;

                if (st.find(board[i][j]) != st.end())
                    return false;
                else
                    st.insert(board[i][j]);
            }
        }

        // check columns
        for (int col = 0; col < m; col++) {
            set<char> st1;
            for (int row = 0; row < n; row++) {

                if (board[row][col] == '.')
                    continue;

                if (st1.find(board[row][col]) != st1.end())
                    return false;
                else
                    st1.insert(board[row][col]);
            }
        }

        // check 3x3 boxes
        for (int sr = 0; sr < n; sr += 3) {
            int er = sr + 2;

            for (int sc = 0; sc < m; sc += 3) {
                int ec = sc + 2;

                if (!check(board, sr, er, sc, ec))
                    return false;
            }
        }

        return true;
    }
};
