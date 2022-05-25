/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */
// BFS Solution
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> Q;
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    Q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        while (!Q.empty()) {
            auto curr = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int newX = curr.first + dx[i];
                int newY = curr.second + dy[i];
                if (isValid(newX, newY, m, n) and dist[newX][newY] == -1) {
                    dist[newX][newY] = dist[curr.first][curr.second] + 1;
                    Q.push({newX, newY});
                }
            }
        }
        return dist;
    }

   private:
    vector<int> dx{0, -1, 1, 0};
    vector<int> dy{1, 0, 0, -1};
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 and x < m and y >= 0 and y < n;
    }
};
// @lc code=end
