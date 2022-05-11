/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string minWindow(string s, string t) {
        int left = 0, right = -1;
        unordered_map<char, int> countS, countT;
        for (char &ch : t) countT[ch]++;
        int minWindowSize = INT_MAX, uniqueChars = countT.size(), curr = 0;
        string res;
        while (true) {
            bool flag1 = true, flag2 = true;
            while (right + 1 < s.size() and curr != uniqueChars) {
                flag2 = false;
                right++;
                char ch = s[right];
                countS[ch]++;
                if (countT[ch] > 0 and countS[ch] == countT[ch]) curr++;
            }
            while (left <= right and curr == uniqueChars) {
                flag1 = false;
                int currWindowSize = right - left + 1;
                if (currWindowSize < minWindowSize) {
                    res = s.substr(left, currWindowSize);
                    minWindowSize = currWindowSize;
                }
                char ch = s[left];
                countS[ch]--;
                if (countS[ch] < countT[ch]) curr--;
                left++;
            }
            if (flag1 and flag2) return res;
        }
    }
};

// @lc code=end
