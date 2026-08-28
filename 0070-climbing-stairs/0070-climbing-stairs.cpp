class Solution {
public:
    int climbStairs(int n) {
        int i = 0;
        int r = back(i , n);
        return r;
    }
    unordered_map<int, int> dp;
    int back(int i , int n){
        if (i == n) return 1;
        if (i > n) return 0;
        if (dp.find(i) != dp.end()){
            return dp[i];
        }
        int a1 = back(i+1, n);
        int a2 = back(i+2, n);
        int ans = a1 + a2;
        dp[i] = ans;
        return ans;
    }
};