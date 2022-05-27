/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        int size = nums.size(), i = 0, j = i + 1, k = size - 1;
        while (i < size - 2) {
            while (j < k) {
                int currSum = nums[i] + nums[j] + nums[k];
                if (currSum < 0) {
                    j++;
                } else if (currSum > 0) {
                    k--;
                } else {
                    int first = nums[i];
                    int second = nums[j];
                    int third = nums[k];
                    vector<int> currRes{first, second, third};
                    res.push_back(currRes);
                    while (nums[j] == second and j < k) j++;
                }
            }
            int left = nums[i];
            while (nums[i] == left and i < size - 2) i++;
            j = i + 1;
            k = size - 1;
        }
        return res;
    }
};
// @lc code=end
