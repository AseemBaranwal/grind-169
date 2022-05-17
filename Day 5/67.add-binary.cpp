/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
class Solution {
   public:
    string addBinary(string a, string b) {
        fastio int m = a.size(), n = b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int maxSize = max(m, n), carry = 0, i = 0;
        string res;
        while (i < maxSize or carry) {
            int curr = carry;
            if (i < m) curr += a[i] - '0';
            if (i < n) curr += b[i] - '0';
            if (curr > 1) {
                curr -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            res.push_back(curr + '0');
            i++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
