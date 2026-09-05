class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums){
            sum += num;
        }


        int target = sum/2;
        vector<vector<int>> dp(n+1);
        for (int i = 0; i <= n; i++){
            vector<int> t(target+1, 0);
            dp[i] = t;
        }
        
        
         dp[0][0] = 1;
        if (sum%2 == 0) 
        {
           for (int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
               dp[i][j] = dp[i-1][j];

               if (j >= nums[i-1]){
                dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]];
               }

            }
           }
        }else{
            return false;
        }

        return dp[n][target] == 1;
    }


};