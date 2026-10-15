class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(i,j,0,board, word)) return true;
            }
        }
        return false;
    }

    bool dfs(int x, int y, int index, vector<vector<char>>& board, string word){
        if(index == word.size()){
            return true;
        }

        if (x < 0 || x >= board.size() ||
            y < 0 || y >= board[0].size())
            return false;

        if(word[index] != board[x][y]) return false;

        char temp = board[x][y];
        board[x][y] = '#';

         bool found =
            dfs(x + 1, y, index + 1, board, word) ||
            dfs(x - 1, y, index + 1, board, word) ||
            dfs(x, y + 1, index + 1, board, word) ||
            dfs(x, y - 1, index + 1, board, word);

        board[x][y] = temp;
        return found;
    }
};