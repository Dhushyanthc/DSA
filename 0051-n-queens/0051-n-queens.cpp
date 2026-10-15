class Solution {
public:
    vector<vector<string>> ans;
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        solve(0,n, board);
        return ans;
    }

    bool is_safe(int row, int col, int n,
             vector<string>& board) {

    
    for (int r = row - 1; r >= 0; r--) {
        if (board[r][col] == 'Q')
            return false;
    }

    
    for (int r = row - 1, c = col - 1;
         r >= 0 && c >= 0; r--, c--) {
        if (board[r][c] == 'Q')
            return false;
    }

    
    for (int r = row - 1, c = col + 1;
         r >= 0 && c < n; r--, c++) {
        if (board[r][c] == 'Q')
            return false;
    }

    return true;
}

    void solve(int row, int n, vector<string>& board){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
        if (is_safe(row, col, n, board)) {
            board[row][col] = 'Q';
            solve(row + 1, n, board);
            board[row][col] = '.';
        }
    }
    }
};