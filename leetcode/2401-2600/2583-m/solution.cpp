// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree
// 2024/10/22

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums;

        stack<pair<TreeNode*, int>> stack;
        stack.push({root, 0});

        while (!stack.empty()) {
            const auto [node, level] = stack.top();
            stack.pop();

            if (sums.size() == level) {
                sums.push_back(node->val);
            } else {
                sums[level] += node->val;
            }

            if (node->left  != nullptr) stack.push({node->left,  level + 1});
            if (node->right != nullptr) stack.push({node->right, level + 1});
        }

        if (sums.size() < k) return -1;

        nth_element(sums.begin(), sums.begin() + k - 1, sums.end(), greater<long long>{});

        return sums[k - 1];
    }
};