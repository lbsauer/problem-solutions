// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii
// 2025/05/29

class Solution {
    vector<vector<int>> build_tree(const vector<vector<int>>& edges) {
        vector<vector<int>> tree(edges.size() + 1);
        for (const auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        return tree;
    }

    void dfs(const vector<vector<int>>& tree, vector<bool>& color, int curr, int prev) {
        color[curr] = !color[prev];

        for (const int next : tree[curr]) {
            if (next != prev) dfs(tree, color, next, curr);
        }
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        const vector<vector<int>> tree1 = build_tree(edges1);
        const vector<vector<int>> tree2 = build_tree(edges2);

        vector<bool> color(tree2.size());
        dfs(tree2, color, 0, 0);

        int max_color = count(color.begin(), color.end(), true);
        max_color = max(max_color, static_cast<int>(tree2.size()) - max_color);

        color.resize(tree1.size());
        dfs(tree1, color, 0, 0);

        const int even_count = count(color.begin(), color.end(), false);
        const int odd_count = tree1.size() - even_count;

        vector<int> target_nodes(tree1.size());
        for (int i = 0; i < tree1.size(); ++i) {
            target_nodes[i] = (color[i] ? odd_count : even_count) + max_color;
        }

        return target_nodes;
    }
};