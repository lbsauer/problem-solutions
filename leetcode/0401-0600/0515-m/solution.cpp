// https://leetcode.com/problems/find-largest-value-in-each-tree-row
// 2025/08/08

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
    void dfs(vector<int>& res, TreeNode* node, int depth) {
        if (node == nullptr) return;

        if (depth == res.size()) {
            res.push_back(node->val);
        } else {
            res[depth] = max(res[depth], node->val);
        }

        dfs(res, node->left, depth + 1);
        dfs(res, node->right, depth + 1);
    }

public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;

        dfs(res, root, 0);

        return res;
    }
};