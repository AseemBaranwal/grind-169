/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
/* Read This comment for the usecase
 * https://leetcode.com/problems/implement-queue-using-stacks/discuss/64284/Do-you-know-when-we-should-use-two-stacks-to-implement-a-queue/65865
 * very intuitive and handy trick in multi-threaded systems
 * */

class MyQueue {
   public:
    stack<int> front, back;
    MyQueue() {}

    void push(int x) { back.push(x); }

    int pop() {
        int val = peek();
        front.pop();
        return val;
    }

    int peek() {
        int val = -1;
        if (!front.empty()) return front.top();
        while (!back.empty()) {
            front.push(back.top());
            back.pop();
        }
        val = front.top();
        return val;
    }

    bool empty() { return front.empty() and back.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
