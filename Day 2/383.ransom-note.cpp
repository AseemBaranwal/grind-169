/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cntArray(26);
        for (int i = 0; i < magazine.size(); i++) cntArray[magazine[i] - 'a']++;
        for (int i = 0; i < ransomNote.size(); i++) {
            if (--cntArray[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
