/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
   public:
    bool isAnagram(string s, string t) {
        /* Time Complexity : O(N)
         * Space Complexity : O(N)
         * This solution takes care of the Unicode characters as well
         * */
        unordered_map<char, int> cnt;
        for (char ch : s) cnt[ch]++;
        for (char ch : t) cnt[ch]--;
        for (auto x : cnt) {
            if (x.second != 0) return false;
        }
        return true;
    }
};
// @lc code=end
