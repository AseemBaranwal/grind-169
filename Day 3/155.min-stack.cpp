/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MinStack {
    // revise
   public:
    vector<pair<int, int> > stack;
    MinStack() {}

    void push(int val) {
        if (stack.empty())
            stack.push_back({val, val});
        else
            stack.push_back({val, min(val, stack.back().second)});
    }

    void pop() { stack.pop_back(); }

    int top() { return stack.back().first; }

    int getMin() { return stack.back().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
