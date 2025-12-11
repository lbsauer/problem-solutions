// https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths
// 2025/10/15

class Solution {
    int find(vector<int>& sets, int v) {
        return sets[v] < 0 ? v : sets[v] = find(sets, sets[v]);
    }

    void unite(vector<int>& sets, int u, int v) {
        u = find(sets, u);
        v = find(sets, v);

        if (u == v) return;

        if (sets[u] > sets[v]) swap(u, v);

        sets[u] += sets[v];
        sets[v] = u;
    }

public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<int> order(queries.size());
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](const int lhs, const int rhs) {
            return queries[lhs][2] < queries[rhs][2];
        });

        sort(edgeList.begin(), edgeList.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[2] < rhs[2];
        });

        vector<int> sets(n, -1);

        vector<bool> res(queries.size());
        for (int i = 0, j = 0; i < res.size(); ++i) {
            const auto& q = queries[order[i]];
            
            while (j < edgeList.size() && edgeList[j][2] < q[2]) {
                unite(sets, edgeList[j][0], edgeList[j][1]);
                ++j;
            }

            res[order[i]] = find(sets, q[0]) == find(sets, q[1]);
        }

        return res;
    }
};