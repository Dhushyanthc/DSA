class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int col = grid[0].size();
        int row = grid.size();

        vector<vector<int>> mat(row+1, vector<int>(col+1, INT_MAX));
        mat[row][col-1] = 0;
        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 0; j--){
                mat[i][j] = grid[i][j] + min(mat[i+1][j], mat[i][j+1]);
            }
        }

        return mat[0][0];
    }
};