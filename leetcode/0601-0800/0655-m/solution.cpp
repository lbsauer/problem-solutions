// https://leetcode.com/problems/print-binary-tree
// 2025/11/22

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
    int height(TreeNode* node) {
        return node == nullptr ? 0 : 1 + max(height(node->left), height(node->right));
    }

    void dfs(vector<vector<string>>& mat, TreeNode* node, int r, int c) {
        mat[r][c] = to_string(node->val);

        if (node->left != nullptr) dfs(mat, node->left, r + 1, c - (1 << (mat.size() - r - 2)));
        if (node->right != nullptr) dfs(mat, node->right, r + 1, c + (1 << (mat.size() - r - 2)));
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        const int h = height(root);

        vector<vector<string>> mat(h, vector<string>((1 << h) - 1));
        dfs(mat, root, 0, mat[0].size() / 2);

        return mat;
    }
};