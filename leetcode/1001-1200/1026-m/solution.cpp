// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor
// 2025/09/26

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
    int dfs(TreeNode* curr, int mn, int mx) {
        if (curr == nullptr) return 0;

        mx = max(mx, curr->val);
        mn = min(mn, curr->val);

        return max({mx - mn, dfs(curr->left, mn, mx), dfs(curr->right, mn, mx)});
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};