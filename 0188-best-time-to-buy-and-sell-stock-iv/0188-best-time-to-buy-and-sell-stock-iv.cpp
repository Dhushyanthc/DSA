class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int i = 0;
        int target = 2*k;
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        return fun(prices, n, i, target, dp);
    }
    int fun(vector<int>& prices, int n, int i, int k, vector<vector<int>>& dp){
        if (i == n) return 0;
        if (k == 0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        if(k%2==0){
            int c1 = fun(prices, n, i+1, k-1, dp) - prices[i];
            int c2 = fun(prices, n, i+1, k, dp);
            return dp[i][k] = max(c1,c2);
        }else{
            int c1 = fun(prices, n, i+1, k - 1, dp) + prices[i];
            int c2 = fun(prices, n, i+1, k, dp);
            return dp[i][k] = max(c1,c2);
        }
        
    }
};