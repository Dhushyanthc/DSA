class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        int c1 = solve(0, cost, n, dp);
        int c2 = solve(1, cost, n, dp);

        return min(c1, c2);
    }

    int solve(int i, vector<int>& cost, int n, vector<int>& dp) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int c1 = solve(i + 1, cost, n, dp);
        int c2 = solve(i + 2, cost, n, dp);

        return dp[i] = cost[i] + min(c1, c2);
    }
};