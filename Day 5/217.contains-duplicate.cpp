/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int ele : nums) {
            if (count[ele]) return true;
            count[ele]++;
        }
        return false;
    }
};
// @lc code=end
