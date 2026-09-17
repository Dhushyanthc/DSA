class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int c1 = solve(0, nums, n - 1, dp1);
        int c2 = solve(1, nums, n, dp2);

        return max(c1, c2);
    }

    int solve(int i, vector<int>& nums, int n, vector<int>& dp) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int c1 = solve(i + 1, nums, n, dp);
        int c2 = nums[i] + solve(i + 2, nums, n, dp);

        return dp[i] = max(c1, c2);
    }
};