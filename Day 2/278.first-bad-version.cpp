/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
   public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        int firstBad = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                firstBad = min(firstBad, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return firstBad;
    }
};
// @lc code=end
