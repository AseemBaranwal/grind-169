/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
   public:
    bool isValid(string s) {
        /* Time Complexity : O(N)
         * Space Complexity : O(N)
         * Time Taken : 15 mins
         * */
        stack<char> brackets;
        for (char &curr : s) {
            bool closingBrace = curr == ')' or curr == ']' or curr == '}';
            if (brackets.empty() and closingBrace)
                return false;
            else if (!closingBrace)
                brackets.push(curr);
            else {
                if (curr == '}' and brackets.top() == '{')
                    brackets.pop();
                else if (curr == ')' and brackets.top() == '(')
                    brackets.pop();
                else if (curr == ']' and brackets.top() == '[')
                    brackets.pop();
                else
                    return false;
            }
        }
        return brackets.empty();
    }
};
// @lc code=end
