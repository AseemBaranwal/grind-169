/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
// Stack Implementation Deletion Reversal
class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        buildStack(st1, s);
        buildStack(st2, t);
        while (!st1.empty() and !st2.empty()) {
            if (st1.top() != st2.top()) return false;
            st1.pop();
            st2.pop();
        }
        return st1.empty() and st2.empty();
    }

   private:
    void buildStack(stack<char> &st, string s) {
        for (char ch : s) {
            if (ch == '#') {
                if (st.empty()) continue;
                st.pop();
            } else
                st.push(ch);
        }
    }
};
// @lc code=end
