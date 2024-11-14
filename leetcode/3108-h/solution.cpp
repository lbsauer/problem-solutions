// https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph
// 2024-11-13

class Solution {
    int find(vector<int>& sets, int u) {
        return sets[u] < 0 ? u : sets[u] = find(sets, sets[u]);
    }

    void unite(vector<int>& sets, vector<int>& cost, int u, int v, int w) {
        u = find(sets, u);
        v = find(sets, v);

        cost[u] &= w;

        if (u == v) return;

        if (u > v) swap(u, v);

        sets[u] += sets[v];
        sets[v] = u;

        cost[u] &= cost[v];
        cost[v] = ~0;
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> sets(n, -1), cost(n, ~0);
        for (const auto& e : edges) {
            unite(sets, cost, e[0], e[1], e[2]);
        }

        vector<int> res(query.size());
        transform(query.begin(), query.end(), res.begin(), [&, s = 0](const auto& q) mutable {
            return (s = find(sets, q[0])) == find(sets, q[1]) ? cost[s] : -1;
        });

        return res;
    }
};