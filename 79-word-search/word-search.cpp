class Solution {
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool find(int i, int j, string& word, vector<vector<char>>& board, int idx,
              int n, int m) {

        if (idx == word.size())
            return true;

        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$')
            return false;

        if (board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';

        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (find(i_, j_, word, board, idx + 1, n, m))
                return true;
        }

        board[i][j] = temp;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0] && find(i, j, word, board, 0, n, m))
                    return true;
            }
        }

        return false;
    }
};