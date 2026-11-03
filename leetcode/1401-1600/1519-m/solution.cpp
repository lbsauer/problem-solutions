// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label
// 2026/08/16

class Solution {
    void dfs(const vector<vector<int>>& graph, const string& labels, int curr, int prev, array<int, 26>& count, vector<int>& res) {
        const int prev_count = count[labels[curr] - 'a'];
        for (const int next : graph[curr]) {
            if (next != prev) dfs(graph, labels, next, curr, count, res);
        }

        res[curr] = ++count[labels[curr] - 'a'] - prev_count;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        array<int, 26> count{};

        vector<int> res(n);
        dfs(graph, labels, 0, 0, count, res);

        return res;
    }
};