/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
   public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (isalnum(s[start]) and isalnum(s[end])) {
                if (tolower(s[start]) != tolower(s[end]))
                    return false;
                start++, end--;
            } else if (!isalnum(s[start]))
                start++;
            else
                end--;
        }
        return true;
    }
};
// @lc code=end
