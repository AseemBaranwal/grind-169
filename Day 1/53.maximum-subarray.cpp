/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxValue = nums[0], curr = max(nums[0], 0);
        for (int i = 1; i < nums.size(); i++) {
            curr += nums[i];
            maxValue = max(maxValue, curr);
            curr = curr < 0 ? 0 : curr;
        }
        return maxValue;
    }
};
// @lc code=end

