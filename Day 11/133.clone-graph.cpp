// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        if (pos.find(node) == pos.end()) {
            pos[node] = new Node(node->val, {});
            for (auto child : node->neighbors) {
                pos[node]->neighbors.push_back(cloneGraph(child));
            }
        }
        return pos[node];
    }

   private:
    unordered_map<Node*, Node*> pos;
};
// @lc code=end
