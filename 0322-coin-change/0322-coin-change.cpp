class Solution {
public:

    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans = solve(0, n, amount, coins, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }

    int solve(int i, int n, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if (i == n) return 1e9;
        if (amount == 0) return 0;
        if(coins[i] > amount) return dp[i][amount] = solve(i+1, n, amount, coins, dp);
        if(dp[i][amount] != -1) return dp[i][amount];
        int yes = 1 + solve(i, n, amount - coins[i], coins, dp);
        int no = solve(i+1, n, amount, coins, dp);
        return dp[i][amount] = min(yes,no);
    }
};
