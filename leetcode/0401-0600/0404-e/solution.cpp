// https://leetcode.com/problems/sum-of-left-leaves
// 2025/08/29

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
    int dfs(TreeNode* node, bool left) {
        if (node == nullptr) return false;

        if (node->left == nullptr && node->right == nullptr) {
            return left ? node->val : 0;
        }

        return dfs(node->left, true) + dfs(node->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};