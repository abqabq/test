class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        if (s.length() < 2) {
            return s;
        }
        
        int length = 1;
        result = s.substr(0, 1);
        for (int i = 1; i < s.length(); i++) {
            for (int j = 0; j <= 1; j++) {
                // case 1 - start and end is the center of palindrome
                // case 2 - only start is the center of palindrome
                int start = i - j, end = i;
                while (start >= 0 && end < s.length() && s[start] == s[end]) {
                    if (length < end - start + 1) {
                        result = s.substr(start, end - start + 1);
                        length = end - start + 1;
                    }
                    start--;
                    end++;
                }
            }
        }
        
        return result;
    }
};
