// https://leetcode.com/problems/binary-tree-postorder-traversal
// 2024/08/24

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
    void dfs(const TreeNode* node, vector<int>& v) {
        if (node == nullptr) return;

        dfs(node->left, v);
        dfs(node->right, v);

        v.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        dfs(root, res);

        return res;
    }
};