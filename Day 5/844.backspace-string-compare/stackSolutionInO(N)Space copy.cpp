/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
// Using two pointer approach
class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        string s1 = trimString(s);
        string s2 = trimString(t);
        return s1.compare(s2) == 0;
    }

   private:
    string trimString(string s) {
        int i = 0, j = 0;
        while (i < s.size()) {
            if (s[i] == '#') {
                j = max(0, j - 1);
            } else {
                s[j] = s[i];
                j++;
            }
            i++;
        }
        s = s.substr(0, j);
        return s;
    }
};
// @lc code=end
