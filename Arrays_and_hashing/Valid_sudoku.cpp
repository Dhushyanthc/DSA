#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int boxes[9][9] = {0};

        for(int i =0; i < 9; i ++)
        {
             for(int j =0; j < 9; j ++)
            {
                if (board[i][j] =='.')
                {
                    continue;
                }

                int val = board[i][j] - '1';

                if (rows[i][val] == 1){
                    return false;
                }

                rows[i][val] = 1;

                if (cols[j][val] == 1){
                    return false;
                }

                cols[j][val] = 1;
                
                int boxIdx = 3*(i/3) + (j/3);
                if (boxes[boxIdx][val] == 1)
                {
                    return false;
                }

                boxes[boxIdx][val] = 1;
            }

        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution solution;

    if (solution.isValidSudoku(board)) {
        cout << "Valid Sudoku" << endl;
    } else {
        cout << "Invalid Sudoku" << endl;
    }

    return 0;
}
