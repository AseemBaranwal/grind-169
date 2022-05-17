// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem543.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
// Struct Usage
struct Node {
    int maxDiameter = 0;
    int height = 0;
    Node(int a, int b) {
        this->maxDiameter = a;
        this->height = b;
    }
};
class Solution {
   public:
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        return height(root).maxDiameter;
    }

   private:
    Node height(TreeNode *root) {
        Node curr = Node(0, 0);
        if (!root) return curr;
        Node leftAnswer = height(root->left), rightAnswer = height(root->right);
        curr.height = 1 + max(leftAnswer.height, rightAnswer.height);
        curr.maxDiameter =
            max(max(leftAnswer.maxDiameter, rightAnswer.maxDiameter),
                leftAnswer.height + rightAnswer.height);
        return curr;
    }
};
// @lc code=end
