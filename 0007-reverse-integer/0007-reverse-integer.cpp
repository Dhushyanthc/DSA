class Solution {
public:
    int reverse(int x) {

        int m = 0;
        while (x != 0){
            int r = x % 10;
            x = x / 10;

            if (m > INT_MAX/10 || ((m == INT_MAX/10 )&& r > 7)) return 0;
            if (m < INT_MIN/10 || ((m == INT_MIN/10 )&& r < -8)) return 0;
            m = m*10 + r;
        }
        return m;
    }
};