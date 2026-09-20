class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<int> dp(n + 1, -1);

        return solve(0, n, s, wordDict, dp);
    }

    bool solve(int i, int n, string& s,
               vector<string>& dict, vector<int>& dp) {

        if(i == n)
            return dp[i] = 1;

        if(dp[i] != -1)
            return dp[i];

        for(auto& word : dict) {

            if(i + word.size() <= n &&
               s.substr(i, word.size()) == word) {

                if(solve(i + word.size(), n, s, dict, dp))
                    return dp[i] = 1;
            }
        }

        return dp[i] = 0;
    }
};