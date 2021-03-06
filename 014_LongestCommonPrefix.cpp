class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if (strs.size() > 0) {
            result = strs[0];
            for (int i = 1; i < strs.size(); i++) {
                int j = 0;
                while (j < result.length() && j < strs[i].length()) {
                    if (result[j] != strs[i][j]) {
                        break;
                    } else {
                        j++;
                    }
                }
                result = result.substr(0, j);
            }
        }
        return result;
    }
};
