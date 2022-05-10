/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        /* Time Complexity : O(N)
         * Space Complexity : O(N)
         * Time Taken : 5 minutes
         * */
        int minValue = prices[0], maxProfitValue = 0;
        for (int i = 1; i < prices.size(); i++) {
            minValue = min(minValue, prices[i]);
            maxProfitValue = max(maxProfitValue, prices[i] - minValue);
        }
        return maxProfitValue;
    }
};
// @lc code=end
