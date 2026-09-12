class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return fun(s, 0, n - 1, dp);
    }

    int fun(string& s, int i, int j,
            vector<vector<int>>& dp) {

        if (i > j)
            return 0;

        if (i == j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];
      
        if (s[i] == s[j]) {
            return dp[i][j] =
                2 + fun(s, i + 1, j - 1, dp);
        }
    
        return dp[i][j] =
            max(
                fun(s, i + 1, j, dp),
                fun(s, i, j - 1, dp)
            );
    }
};