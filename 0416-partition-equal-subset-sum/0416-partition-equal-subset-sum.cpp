class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n:nums){
            sum+=n;
        }


        if(sum%2 != 0) return false;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>((sum/2)+1,-1));

        int res = solve(0, sum/2,nums,dp);
        return (res == 1)?true:false;

    }

    int solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if (target == 0) return dp[i][target] = 1;
        if(i == nums.size()) return dp[i][target] = 0;

        if(dp[i][target] != -1) return dp[i][target];
        if(nums[i] <= target){
        int take = solve(i+1, target - nums[i], nums, dp);
        int skip = solve(i+1, target, nums,dp);
        return dp[i][target] = max(take, skip);
        }
        return solve(i+1, target, nums, dp);
    }
};
