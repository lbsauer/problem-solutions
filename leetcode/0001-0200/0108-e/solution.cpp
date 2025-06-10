// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
// 2024/11/17

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
    TreeNode* build(const vector<int>& nums, const int l, const int r) {
        if (l >= r) return nullptr;

        const int m = l + (r - l) / 2;

        TreeNode* node = new TreeNode(nums[m]);
        
        node->left  = build(nums, l, m);
        node->right = build(nums, m + 1, r);

        return node;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
};