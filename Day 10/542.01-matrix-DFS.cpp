// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem542.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */
// DFS Solution -- TLE
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (auto& vec : vis) fill(vec.begin(), vec.end(), 0);
                res[i][j] = minDistance(mat, vis, i, j, m, n);
            }
        }
        return res;
    }

   private:
    vector<int> dx{0, 1, -1, 0};
    vector<int> dy{1, 0, 0, -1};

    int minDistance(vector<vector<int>>& mat, vector<vector<int>>& vis, int r,
                    int c, int m, int n) {
        if (mat[r][c] == 0) return 0;
        vis[r][c] = 1;
        int res = INT_MAX - 1;
        for (int i = 0; i < 4; i++) {
            if (isValid(vis, r + dx[i], c + dy[i], m, n)) {
                res =
                    min(res, minDistance(mat, vis, r + dx[i], c + dy[i], m, n));
                vis[r + dx[i]][c + dy[i]] = 0;
            }
        }
        return res + 1;
    }
    bool isValid(vector<vector<int>>& vis, int r, int c, int m, int n) {
        return r < m and r >= 0 and c < n and c >= 0 and vis[r][c] == 0;
    }
};
// @lc code=end
