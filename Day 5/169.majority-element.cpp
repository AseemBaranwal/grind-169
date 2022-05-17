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
        // Moore's Voting Algorithm
        int counter = 0, targetElement;
        for (int ele : nums) {
            if (!counter) targetElement = ele;
            counter += (targetElement == ele) ? 1 : -1;
        }
        return targetElement;
    }
};
// @lc code=end
