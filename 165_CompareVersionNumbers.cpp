class Solution {
public:
    int compareVersion(string version1, string version2) {
        while (version1 != version2) {
            int gap = stoi(version1) - stoi(version2);
            if (gap == 0) {
                version1 = getSubstr(version1);
                version2 = getSubstr(version2);
            } else {
                return gap < 0 ? -1 : 1;
            }
        }
        
        return 0;
    }
    
    string getSubstr(string version) {
        for (int i = 0; i < version.length(); i++) {
            if (version[i] == '.') {
                return version.substr(i + 1);
            }
        }
        
        return "0";
    }
};
