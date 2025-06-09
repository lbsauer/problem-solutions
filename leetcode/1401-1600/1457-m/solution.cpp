// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree
// 2024/08/16

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
    void dfs(TreeNode* node, bitset<9>& odd, int& path_count) {
        odd.flip(node->val - 1);
        
        if (node->left == nullptr && node->right == nullptr) {
            path_count += odd.count() <= 1;
        }

        if (node->left != nullptr) dfs(node->left, odd, path_count);
        if (node->right != nullptr) dfs(node->right, odd, path_count);

        odd.flip(node->val - 1);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        bitset<9> odd;

        int path_count = 0;

        dfs(root, odd, path_count);

        return path_count;
    }
};