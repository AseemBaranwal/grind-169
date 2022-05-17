/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
// Roman Number Problem

class Solution {
   public:
    int romanToInt(string &s) {
        map<char, pair<int, int>> numValue;
        numValue['I'] = {0, 1};
        numValue['V'] = {1, 5};
        numValue['X'] = {2, 10};
        numValue['L'] = {3, 50};
        numValue['C'] = {4, 100};
        numValue['D'] = {5, 500};
        numValue['M'] = {6, 1000};
        int currPos = -1;
        int resNum = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            int num = numValue[s[i]].second;
            if (numValue[s[i]].first < currPos) {
                resNum -= num;
            } else {
                resNum += num;
                currPos = numValue[s[i]].first;
            }
        }
        return resNum;
    }
};
// @lc code=end
