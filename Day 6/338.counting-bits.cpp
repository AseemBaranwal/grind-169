/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
// Bit Manipulation
// Revisit
class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++) res[i] = res[i / 2] + (i & 1);
        return res;
    }
};
// @lc code=end
