/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
// Bit Manipulation
// Revisit Method 4
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int numXor = 0;
        for (int number : nums) numXor ^= number;
        return numXor;
    }
};
// @lc code=end
