/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int longestPalindrome(string s) {
        int oddContribution = 0, evenContribution = 0, maxOdds = 0;
        bool oddPresent = true;
        unordered_map<char, int> count;
        for (char &ch : s) count[ch]++;
        for (auto x : count) {
            if (x.second & 1) {
                if (oddPresent) {
                    oddContribution++;
                    oddPresent = false;
                }
                oddContribution += (x.second > 2) ? x.second - 1 : 0;
            } else {
                evenContribution += x.second;
            }
        }
        return evenContribution + oddContribution;
    }
};
// @lc code=end
