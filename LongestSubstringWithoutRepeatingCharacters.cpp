class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_occur;
        int result = 0;
        
        int start = 0, end = 0;
        while (end < s.length()) {
            if (last_occur.find(s[end]) == last_occur.end() || last_occur[s[end]] < start) {
                result = max(result, end - start + 1);
            } else {
                start = last_occur[s[end]] + 1;
            }
            
            last_occur[s[end]] = end;
            end++;
        }
        
        return result;
    }
};
