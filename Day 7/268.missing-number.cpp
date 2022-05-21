/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int num = 0;
        for (int i = 1; i <= nums.size(); i++) num ^= i;
        for (int i = 0; i < nums.size(); i++) num ^= nums[i];
        return num;
    }
};
// @lc code=end
