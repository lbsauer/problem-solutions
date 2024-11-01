// https://leetcode.com/problems/create-binary-tree-from-descriptions
// 2024/07/15

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        int root = 0;

        for (vector<int>& desc : descriptions) {
            if (!nodes.count(desc[0])) {
                nodes[desc[0]] = new TreeNode(desc[0]);
                root ^= desc[0];
            }

            if (!nodes.count(desc[1])) {
                nodes[desc[1]] = new TreeNode(desc[1]);
            } else {
                root ^= desc[1];
            }

            if (desc[2] == 1) {
                nodes[desc[0]]->left = nodes[desc[1]];
            } else {
                nodes[desc[0]]->right = nodes[desc[1]];
            }
        }

        return nodes[root];
    }
};