/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int replacementsAllowed = 0;
        int maxWindow = 0, maxFrequency = 0;
        unordered_map<char, int> count;
        while (right < s.size()) {
            count[s[right]]++;
            maxFrequency = max(maxFrequency, count[s[right]]);
            int currentWindowSize = right - left + 1;
            while (currentWindowSize - maxFrequency > k) {
                count[s[left]]--;
                left++;
                currentWindowSize = right - left + 1;
            }
            maxWindow = max(maxWindow, currentWindowSize);
            right++;
        }
        return maxWindow;
    }
};
// @lc code=end
