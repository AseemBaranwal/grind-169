/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        /* Time Complexity : O(N)
         * Space Complexity : O(1)
         * KMP Algorithm (Knuth Morris Pratt Algo)
         * */
        int size = s.size();
        int maxLength = 0, start = 0;
        unordered_map<char, int> lastPosition;
        for (int i = 0; i < size; i++) {
            if (lastPosition[s[i]] > 0) {
                start = max(lastPosition[s[i]], start);
            }
            maxLength = max(maxLength, i - start + 1);
            lastPosition[s[i]] = i + 1;
        }
        return maxLength;
    }
};
// @lc code=end
