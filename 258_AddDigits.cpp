class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};

class Solution {
public:
    int addDigits(int num) {
        while (num > 9) {
            int n = num;
            num = 0;
            while (n) {
                num += n % 10;
                n /= 10;
            }
        }
        
        return num;
    }
};
