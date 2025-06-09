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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        deque<TreeNode*> stack{root};
        while (!stack.empty()) {
            TreeNode* curr = stack.back();
            stack.pop_back();

            if (curr == nullptr) continue;

            res.push_back(curr->val);

            stack.push_back(curr->left);
            stack.push_back(curr->right);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};