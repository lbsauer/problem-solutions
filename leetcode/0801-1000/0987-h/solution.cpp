// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree
// 2025/11/30

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
    pair<int, int> dfs_col(TreeNode* curr, int row, int col) {
        if (curr == nullptr) return {0, 0};

        const auto [lmin, lmax] = dfs_col(curr->left, row + 1, col - 1);
        const auto [rmin, rmax] = dfs_col(curr->right, row + 1, col + 1);

        return {min({col, lmin, rmin}), max({col, lmax, rmax})};
    }

    void dfs(vector<vector<pair<int, int>>>& cols, TreeNode* curr, int row, int col) {
        if (curr->left != nullptr) dfs(cols, curr->left, row + 1, col - 1);

        cols[col].emplace_back(row, curr->val);

        if (curr->right != nullptr) dfs(cols, curr->right, row + 1, col + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        const auto [min_col, max_col] = dfs_col(root, 0, 0);

        vector<vector<pair<int, int>>> cols(max_col - min_col + 1);
        dfs(cols, root, 0, -min_col);

        vector<vector<int>> res(cols.size());
        for (int i = 0; i < cols.size(); ++i) {
            sort(cols[i].begin(), cols[i].end());

            res[i].resize(cols[i].size());
            for (int j = 0; j < res[i].size(); ++j) {
                res[i][j] = cols[i][j].second;
            }
        }

        return res;
    }
};