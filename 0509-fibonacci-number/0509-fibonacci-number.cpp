class Solution {
public:
    
    int fib(int n) {
        int prev_prev = 0;
        int prev = 1;
        int ans = 0;
        if(n == 0 || n == 1) return n;
        for (int i = 2 ; i <= n; i++)
        {
            ans = prev_prev + prev;
            prev_prev = prev;
            prev = ans;
        }
        return ans;
    }
};