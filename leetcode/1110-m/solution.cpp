// https://leetcode.com/problems/delete-nodes-and-return-forest
// 2024/07/16

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        unordered_set<TreeNode*> roots{root};

        dfs(&root, del, roots);

        return vector<TreeNode*>(roots.begin(), roots.end());
    }

    void dfs(TreeNode** root, unordered_set<int>& del, unordered_set<TreeNode*>& roots) {
        TreeNode* curr = *root;

        bool b = del.count(curr->val);
        if (b) {
            roots.erase(curr);
            *root = nullptr;
        }

        if (curr->left != nullptr) {
            if (b) roots.insert(curr->left);
            dfs(&curr->left, del, roots);
        }
        if (curr->right != nullptr) {
            if (b) roots.insert(curr->right);
            dfs(&curr->right, del, roots);
        }
    }
};