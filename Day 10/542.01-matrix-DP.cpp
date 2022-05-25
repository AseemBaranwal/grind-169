/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */
// DP Solution
// Revise
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), maxValue = m + n;
        // Solving for top and left
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) continue;
                int top = maxValue, left = maxValue;
                if (i - 1 >= 0) top = mat[i - 1][j];
                if (j - 1 >= 0) left = mat[i][j - 1];
                mat[i][j] = min(top, left) + 1;
            }
        }
        // Solving for right and bottom
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (mat[i][j] == 0) continue;
                int right = maxValue, bottom = maxValue;
                if (i + 1 < m) bottom = mat[i + 1][j];
                if (j + 1 < n) right = mat[i][j + 1];
                mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};
// @lc code=end
