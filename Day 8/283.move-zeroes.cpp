/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 1;
        while (j < nums.size()) {
            if (nums[j] != 0 and nums[i] == 0) {
                swap(nums[j], nums[i]);
                i++, j++;
            } else if (nums[j] == 0 and nums[i] != 0) {
                i = j;
                j++;
            } else
                j++;
        }
    }
};
// @lc code=end
