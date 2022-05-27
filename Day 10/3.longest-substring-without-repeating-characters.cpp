/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
// 2 pointer solution
// Revisit
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int maxLength = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (lastIndex[s[i]] > 0) {
                start = max(start, lastIndex[s[i]]);
            }
            maxLength = max(maxLength, i - start + 1);
            lastIndex[s[i]] = i + 1;
        }
        return maxLength;
    }
};
// @lc code=end
