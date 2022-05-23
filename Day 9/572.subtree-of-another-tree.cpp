// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem572.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root and !subRoot) return true;
        if (!root or !subRoot) return false;
        return isSameSubtree(root, subRoot) or isSubtree(root->left, subRoot) or
               isSubtree(root->right, subRoot);
    }

   private:
    bool isSameSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root and !subRoot) return true;
        if (!root or !subRoot) return false;
        return root->val == subRoot->val and
               isSameSubtree(root->left, subRoot->left) and
               isSameSubtree(root->right, subRoot->right);
    }
};
// @lc code=end
