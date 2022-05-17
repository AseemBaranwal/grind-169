/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int n = nums.size();
        for (int ele : nums) count[ele]++;
        for (auto ele : count)
            if (ele.second > n / 2) return ele.first;
        return -1;
    }
};
// @lc code=end
