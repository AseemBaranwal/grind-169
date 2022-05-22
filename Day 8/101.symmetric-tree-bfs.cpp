/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

#include <bits/stdc++.h>
using namespace std;
// Revisit
// BFS
// @lc code=start
class Solution {
   public:
    bool isSymmetric(TreeNode *root) {
        // From Discussions
        if (!root) return root;
        queue<TreeNode *> Q;
        Q.push(root->left);
        Q.push(root->right);
        while (!Q.empty()) {
            TreeNode *leftSubtree = Q.front();
            Q.pop();
            TreeNode *rightSubtree = Q.front();
            Q.pop();
            if (leftSubtree and !rightSubtree) return false;
            if (!leftSubtree and rightSubtree) return false;
            if (leftSubtree and rightSubtree) {
                if (leftSubtree->val != rightSubtree->val) return false;
                Q.push(leftSubtree->left);
                Q.push(rightSubtree->right);
                Q.push(leftSubtree->right);
                Q.push(rightSubtree->left);
            }
        }
        return true;
    }
};
// @lc code=end
