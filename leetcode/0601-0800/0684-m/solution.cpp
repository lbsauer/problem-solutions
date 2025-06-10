// https://leetcode.com/problems/redundant-connection
// 2024/11/05

class Solution {
    int find(vector<int>& sets, int v) {
        return sets[v] < 0 ? v : sets[v] = find(sets, sets[v]);
    }

    bool unite(vector<int>& sets, int u, int v) {
        u = find(sets, u);
        v = find(sets, v);

        if (u == v) return false;

        if (sets[u] > sets[v]) swap(u, v);

        sets[u] += sets[v];
        sets[v] = u;

        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> sets(edges.size(), -1);
        for (const auto& e : edges) {
            if (!unite(sets, e[0] - 1, e[1] - 1)) return e;
        }

        return {};
    }
};