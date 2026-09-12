class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return fun(s, 0, n - 1, dp);
    }

    int fun(string& s, int i, int j,
            vector<vector<int>>& dp) {

        // No characters
        if (i > j)
            return 0;

        // One character
        if (i == j)
            return 1;

        // Already solved
        if (dp[i][j] != -1)
            return dp[i][j];

        // Both ends match
        if (s[i] == s[j]) {
            return dp[i][j] =
                2 + fun(s, i + 1, j - 1, dp);
        }

        // Ends don't match
        return dp[i][j] =
            max(
                fun(s, i + 1, j, dp),
                fun(s, i, j - 1, dp)
            );
    }
};