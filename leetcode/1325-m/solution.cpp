// https://leetcode.com/problems/delete-leaves-with-a-given-value
// 2024/05/16

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void remove(TreeNode** node, const int target) {
        if (*node == nullptr) return;

        TreeNode* n = *node;

        remove(&n->left, target);
        remove(&n->right, target);

        if (n->val == target && n->left == nullptr && n->right == nullptr) {
            *node = nullptr;
        }
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        remove(&root, target);

        return root;
    }
};