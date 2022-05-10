/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
struct Node {
    bool isBalanced = true;
    int height = 0;
    Node(bool a, int b) {
        this->isBalanced = a;
        this->height = b;
    }
};

class Solution {
   public:
    bool isBalanced(TreeNode* root) { return isBalancedUtil(root)->isBalanced; }

   private:
    int height(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    Node* isBalancedUtil(TreeNode* root) {
        Node* node = new Node(true, 0);
        if (!root) return node;
        Node* leftAnswer = isBalancedUtil(root->left);
        Node* rightAnswer = isBalancedUtil(root->right);
        node->height = 1 + max(leftAnswer->height, rightAnswer->height);
        node->isBalanced = leftAnswer->isBalanced and
                           rightAnswer->isBalanced and
                           abs(leftAnswer->height - rightAnswer->height) <= 1;
        return node;
    }
};
// @lc code=end
