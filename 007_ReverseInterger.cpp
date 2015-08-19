class Solution {
public:
    int reverse(int x) {
        int sign = x > 0 ? 1 : -1;
        
        int num = abs(x);
        int result = 0;
        while (num) {
            int digit = num % 10;
            if (result > (INT_MAX - digit) / 10) {
                return 0;
            }
            
            result = result * 10 + digit;
            num /= 10;
        }
        
        return sign == 1 ? result : -result;
    }
};
