class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        fun(text1, text2, n, m, i, j, dp);
        return dp[0][0];
        
    }

    int fun(string& text1, string& text2, int n, int m, int i, int j, vector<vector<int>>& dp){

        if (i == n || j == m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if (text1[i] == text2[j]) return dp[i][j] = 1 + fun(text1, text2, n, m, i+1, j+1, dp);

        int c1 = fun(text1, text2, n, m, i+1, j, dp);
        int c2 = fun(text1, text2, n, m, i, j+1, dp);
        return dp[i][j] = max(c1,c2);
    }
};