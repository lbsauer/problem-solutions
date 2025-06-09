// https://leetcode.com/problems/maximum-depth-of-binary-tree
// 2024/08/25

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
    void dfs(TreeNode* node, const int depth, int& max_depth) {
        if (node == nullptr) return;

        max_depth = max(max_depth, depth + 1);

        dfs(node->left, depth + 1, max_depth);
        dfs(node->right, depth + 1, max_depth);
    }

    int maxDepth(TreeNode* root) {
        int max_depth = 0;

        dfs(root, 0, max_depth);
        
        return max_depth;
    }
};