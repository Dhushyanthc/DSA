class Solution {
public:
    int addDigits(int num) {
        if (num < 10) return num;

        int digit_sum = 0;
        while (num > 0){
            digit_sum += num % 10;
            num /=10;
        }
        return addDigits(digit_sum);
    }
};