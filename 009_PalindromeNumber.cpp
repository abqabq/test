class Solution {
public:
    bool isPalindrome(int x) {
        // negative number and 10, 20, ..., 90, 10000.. etc
        if(x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        
        int reverse = 0;
        while(x > reverse)
        {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        
        return (reverse == x || x == reverse / 10 /* odd-digit number case, e.g., 111 */);
    }
};
