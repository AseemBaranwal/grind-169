/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> res;
        int index = 0;
        while (index < intervals.size() and
               newInterval[0] > intervals[index][1]) {
            res.push_back(intervals[index++]);
        }
        while (index < intervals.size() and
               newInterval[1] >= intervals[index][0]) {
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        res.push_back(newInterval);
        while (index < intervals.size()) {
            res.push_back(intervals[index++]);
        }
        return res;
    }
};
// @lc code=end
