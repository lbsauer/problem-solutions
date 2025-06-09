// https://leetcode.com/problems/n-ary-tree-postorder-traversal
// 2024/08/25

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(const Node* node, vector<int>& res) {
        if (node == nullptr) return;

        for (const Node* c : node->children) {
            dfs(c, res);
        }

        res.push_back(node->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> res;

        dfs(root, res);

        return res;
    }
};