/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix = strs[0];
        int currentSize = commonPrefix.size();
        for (string str : strs) {
            if (currentSize == 0) return commonPrefix;
            bool fullPrefix = true;
            for (int i = 0; i < min(commonPrefix.size(), str.size()); i++) {
                if (str[i] != commonPrefix[i]) {
                    commonPrefix = commonPrefix.substr(0, i);
                    currentSize = commonPrefix.size();
                    fullPrefix = false;
                    break;
                }
            }
            if (fullPrefix and str.size() < commonPrefix.size()) {
                commonPrefix = str;
                currentSize = commonPrefix.size();
            }
        }
        return commonPrefix;
    }
};
// @lc code=end
