/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int number = 0;
        for (int i = 1; i <= nums.size(); i++) number ^= i;
        for (int i = 0; i < nums.size(); i++) number ^= nums[i];
        return number;
    }
};
// @lc code=end
