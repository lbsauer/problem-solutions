// https://leetcode.com/problems/reachable-nodes-with-restrictions
// 2024/11/05

class Solution {
    int find(vector<int>& sets, int x) {
        return sets[x] < 0 ? x : sets[x] = find(sets, sets[x]);
    }

    void unite(vector<int>& sets, int x, int y) {
        x = find(sets, x);
        y = find(sets, y);

        if (x == y) return;

        if (sets[x] > sets[y]) swap(x, y);

        sets[x] += sets[y];
        sets[y] = x;
    }

public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool> rd(n);
        for (const int r : restricted) {
            rd[r] = true;
        }
 
        vector<int> sets(n, -1);
        for (const auto& e : edges) {
            if (rd[e[0]] || rd[e[1]]) continue;
 
            unite(sets, e[0], e[1]);
        }
 
        return -sets[find(sets, 0)];
    }
};