/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
bool sortMe(vector<int> &x, vector<int> &y) {
    return pow(x[0], 2) + pow(x[1], 2) < pow(y[0], 2) + pow(y[1], 2);
}
class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        sort(points.begin(), points.end(), sortMe);
        while (points.size() != k) points.pop_back();
        return points;
    }
};
// @lc code=end
