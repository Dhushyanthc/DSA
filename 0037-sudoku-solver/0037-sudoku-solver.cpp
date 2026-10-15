class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,board);
    }

    bool is_valid(int row, int col, char val, vector<vector<char>>& board) {
    for (int j = 0; j < 9; ++j) {
        if (board[row][j] == val) {
            return false;
        }
    }

    for (int i = 0; i < 9; ++i) {
        if (board[i][col] == val) {
            return false;
        }
    }

    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[start_row + i][start_col + j] == val) {
                return false;
            }
        }
    }

    return true;
}

bool solve(int pos, vector<vector<char>>& board) {
        if (pos == 81)
            return true;

        int row = pos / 9;
        int col = pos % 9;

        if (board[row][col] != '.') {
            return solve(pos + 1, board);
        }

        for (char val = '1'; val <= '9'; val++) {
            if (is_valid(row, col, val, board)) {
                board[row][col] = val;

                if (solve(pos + 1, board))
                    return true;

                board[row][col] = '.';
            }
        }

        return false;
    }
};