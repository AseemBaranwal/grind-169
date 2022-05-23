/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1;
        vector<int> res(n);
        int k = n - 1;
        while (k >= 0) {
            if (abs(nums[i]) > abs(nums[j])) {
                res[k--] = nums[i] * nums[i];
                i++;
            } else {
                res[k--] = nums[j] * nums[j];
                j--;
            }
        }
        return res;
    }
};
// @lc code=end
