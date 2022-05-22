/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// Revisit
// Constraints, Edge Case
// @lc code=start
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long reversedNumber = reverse(x);
        return (long)x == reversedNumber;
    }

   private:
    long reverse(int num) {
        long rev = 0;
        while (num) {
            rev *= 10;
            rev += num % 10;
            num /= 10;
        }
        return rev;
    }
};
// @lc code=end
