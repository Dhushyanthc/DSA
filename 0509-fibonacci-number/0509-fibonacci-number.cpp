class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;
        int sum = a + b;
         if (n == 0 )
        {
            return 0;
        }
        if (n == 1 )
        {
            return 1;
        }
        if (n == 2){
            return 1;
        }
        for (int i = 2; i < n; i++){
            int c = a;
            a = b;
            b += c;
        }
        return a+b;
    }
};