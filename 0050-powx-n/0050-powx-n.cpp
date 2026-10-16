class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if(n==0) return 1.0;
        if(x == 0) return 0.0;
        if(x == 1) return 1.0;
        if(x == -1 && n%2==0) return 1.0;
        if(x == -1 && n%2==1) return -1.0;
        if (exp < 0) {
           
            exp = -exp;
        }

        double result = 1.0;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= x;
            }

            x *= x;
            exp /= 2;
        }

        return n < 0 ? 1.0 / result : result;
    }
};