/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
// Trie Solution
// Revisit
class TrieNode {
   public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
    char val;
    TrieNode() {}
    TrieNode(char ch) { this->val = ch; }
};

class Trie {
   private:
    TrieNode* root = NULL;

   public:
    Trie() { root = new TrieNode(); }

    TrieNode* getRoot() { return root; }

    void insertString(string str) {
        TrieNode* temp = root;
        for (char ch : str) {
            if (temp->children.find(ch) == temp->children.end()) {
                temp->children[ch] = new TrieNode(ch);
            }
            temp = temp->children[ch];
        }
        temp->isWord = true;
    }
};

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* pTrie = new Trie();
        for (string str : strs) {
            pTrie->insertString(str);
        }
        string res = "";
        TrieNode* curr = pTrie->getRoot();
        while (curr and !curr->isWord and curr->children.size() == 1) {
            auto it = curr->children.begin();
            res.push_back(it->first);
            curr = it->second;
        }
        return res;
    }
};
// @lc code=end
