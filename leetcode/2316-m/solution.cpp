// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph
// 2024/11/11

class Solution {
    int find(vector<int>& sets, int x) {
        return sets[x] < 0 ? x : sets[x] = find(sets, sets[x]);
    }

    void unite(vector<int>& sets, int x, int y) {
        x = find(sets, x);
        y = find(sets, y);

        if (x == y) return;

        if (x > y) swap(x, y);

        sets[x] += sets[y];
        sets[y] = x;
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> sets(n, -1);
        for (const auto& e : edges) {
            unite(sets, e[0], e[1]);
        }

        long long res = 0;
        for_each(sets.begin(), sets.end(), [&](long long s) { res -= min(s, 0ll) * (n + s); });

        return res >> 1;
    }
};