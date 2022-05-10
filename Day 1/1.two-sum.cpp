/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* Time Complexity : O(N)
         * Space Complexity : O(N)
         * Time taken to Solve : 6 minutes
        */
        unordered_map<int, int> idx;
        for(int i = 0; i < nums.size(); i++) {
            if(idx[target - nums[i]] != 0) {
                return {idx[target - nums[i]] - 1, i};
            }
            idx[nums[i]] = i+1;
        }
        return {};
    }
};
// @lc code=end

