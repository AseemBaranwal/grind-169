// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem234.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// Modified Tortoise Hare Problem
// Revisit
class Solution {
   public:
    bool isPalindrome(ListNode *head) {
        if (!head or !head->next) return true;
        ListNode *slow = head, *fast = head->next->next;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) slow = slow->next;
        slow->next = reverse(slow->next);
        ListNode *firstHalf = head, *secondHalf = slow->next;
        while (firstHalf and secondHalf and firstHalf->val == secondHalf->val) {
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        bool flag = (secondHalf == nullptr);
        if (fast) firstHalf = firstHalf->next;
        firstHalf->next = reverse(firstHalf->next);
        return flag;
    }

   private:
    ListNode *reverse(ListNode *head) {
        if (!head or !head->next) return head;
        ListNode *temp = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
    }
};
// @lc code=end
