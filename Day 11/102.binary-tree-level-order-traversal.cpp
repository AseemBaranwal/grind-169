/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty()) {
            int levelSize = Q.size();
            vector<int> level;
            for (int i = 0; i < levelSize; i++) {
                TreeNode *curr = Q.front();
                Q.pop();
                level.push_back(curr->val);
                if (curr->left) Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
            }
            res.push_back(level);
        }
        return res;
    }
};
// @lc code=end
