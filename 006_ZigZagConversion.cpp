class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 0) {
            return "";
        } else if (numRows == 1) {
            return s;
        }
        
        int row = 0;
        int step = 1;
        vector<string> result(numRows, "");
        // figure out which row it belongs to as we walk through each character
        for (int i = 0; i < s.length(); i++) {
            result[row].push_back(s[i]);
            if (row == numRows - 1) {
                step = -1;
            } else if (row == 0) {
                step = 1;
            }
            row += step;
        }
        
        string res = "";
        for (auto &s : result) {
            res += s;
        }
        return res;
    }
};
