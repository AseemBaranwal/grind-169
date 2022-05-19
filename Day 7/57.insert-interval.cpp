/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

#include <bits/stdc++.h>
using namespace std;
// Revisit
// Two Pointer
// @lc code=start
class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> res;
        int currIndex = 0;
        while (currIndex < intervals.size() and
               intervals[currIndex][1] < newInterval[0])
            res.push_back(intervals[currIndex++]);
        while (currIndex < intervals.size() and
               intervals[currIndex][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[currIndex][0], newInterval[0]);
            newInterval[1] = max(intervals[currIndex][1], newInterval[1]);
            currIndex++;
        }
        res.push_back(newInterval);
        while (currIndex < intervals.size()) {
            res.push_back(intervals[currIndex++]);
        }
        return res;
    }
};
// @lc code=end
