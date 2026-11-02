// https://leetcode.com/problems/minimum-cost-path-with-edge-reversals
// 2026/01/29

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& e : edges) {
            graph[e[0]].emplace_back(e[1], e[2]);
            graph[e[1]].emplace_back(e[0], e[2] * 2);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        while (!pq.empty()) {
            const auto [w, v] = pq.top();
            pq.pop();

            if (dist[v] < w) continue;
            
            if (v == n - 1) return w;

            for (const auto [nv, nw] : graph[v]) {
                if (w + nw < dist[nv]) {
                    dist[nv] = w + nw;
                    pq.emplace(w + nw, nv);
                }
            }
        }

        return -1;
    }
};