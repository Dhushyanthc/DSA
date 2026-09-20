class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solve(0, -1, nums, dp);
    }

    int solve(int i, int prev, vector<int>& a,vector<vector<int>>& dp){
        if(i==a.size()) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        if(prev == -1 || a[i]>a[prev]){
            int c1 = 1+solve(i+1, i, a, dp);
            int c2 = solve(i+1, prev, a,dp);
            return dp[i][prev+1] = max(c1,c2);
        }

        return dp[i][prev+1] = solve(i+1, prev, a, dp);
    }
};
