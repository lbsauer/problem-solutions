// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree
// 2026/01/06

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
    void dfs(vector<int>& sum, TreeNode* node, int level) {
        if (node == nullptr) return;

        if (level >= sum.size()) {
            sum.push_back(node->val);
        } else {
            sum[level] += node->val;
        }

        dfs(sum, node->left, level + 1);
        dfs(sum, node->right, level + 1);
    }

public:
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        dfs(sum, root, 0);

        return 1 + distance(sum.begin(), max_element(sum.begin(), sum.end()));
    }
};