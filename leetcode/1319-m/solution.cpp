// https://leetcode.com/problems/number-of-operations-to-make-network-connected
// 2024-11-07

class Solution {
    int find(vector<int>& parent, int x) {
        return parent[x] < 0 ? x : parent[x] = find(parent, parent[x]);
    }

    void unite(vector<int>& parent, int x, int y) {
        int px = find(parent, x);
        int py = find(parent, y);

        if (px == py) return;

        if (px > py) swap(px, py);

        parent[px] += parent[py];
        parent[py] = px;
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<int> parent(n, -1);
        for (const auto& c : connections) {
            unite(parent, c[0], c[1]);
        }

        vector<bool> sets(n);
        for (int i = 0; i < n; ++i) {
            sets[find(parent, i)] = true;
        }

        return count(sets.begin(), sets.end(), true) - 1;
    }
};