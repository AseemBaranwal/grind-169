/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rowCount = image.size(), colCount = image[0].size();
        int color = image[sr][sc];
        if(color != newColor) {
            image[sr][sc] = newColor;
            for (int i = 0; i < 4; i++) {
                int row = sr + dx[i];
                int col = sc + dy[i];
                if (isValid(image, row, col, rowCount, colCount, color)) {
                    image[row][col] = color;
                    floodFill(image, row, col, newColor);
                }
            }
        }
        return image;
    }

   private:
    bool isValid(vector<vector<int>>& image, int r, int c, int rows, int cols, int color) {
        return r >= 0 and c >= 0 and r < rows and c < cols and image[r][c] == color;
    }
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
};
// @lc code=end
