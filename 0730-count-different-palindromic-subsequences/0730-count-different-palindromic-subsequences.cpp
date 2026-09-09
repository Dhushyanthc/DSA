class Solution {
public:
    const int mod = 1000000007;
    int countPalindromicSubsequences(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),-1));
        int n = s.size();
        int i = 0;
        int j = n -1;
        solve(s,i,j,dp);
        return dp[0][n-1];
    }

    int solve(string& s, int i, int j, vector<vector<int>>& dp){
        if (i>j) return 0;
        if(i==j) return dp[i][j] = 1;
        if (dp[i][j] != -1) return dp[i][j];
        long long ans;
       
        if (s[i]!=s[j]){
            ans = solve(s,i+1,j,dp) + solve(s, i, j-1, dp) - solve(s,i+1, j-1, dp);
        }else{
            int left = i + 1;
            int right = j - 1;
            while (left <= right && s[left]!=s[i]){
                left++;
            }
            while (right >= left && s[right]!=s[i]){
                right--;
            }
            if(left>right){
                ans = 2LL*solve(s,i+1,j-1,dp) + 2;
            }else if(left == right){
                ans = 2LL*solve(s,i+1,j-1,dp) + 1;
            }else{
                ans = 2LL*solve(s,i+1,j-1,dp) - solve(s,left+1,right-1,dp);
            }
        }
        ans = (ans%mod+mod)%mod;
        return dp[i][j] = ans;
    }
};