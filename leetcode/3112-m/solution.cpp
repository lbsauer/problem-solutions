// https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes
// 2024-11-13

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& e : edges) {
            graph[e[0]].emplace_back(e[1], e[2]);
            graph[e[1]].emplace_back(e[0], e[2]);
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            const auto [w, v] = pq.top();
            pq.pop();

            if (w > dist[v]) continue;

            for (const auto [nv, nw] : graph[v]) {
                const int d = w + nw;

                if (d < dist[nv] && d < disappear[nv]) {
                    dist[nv] = d;
                    pq.emplace(d, nv);
                }
            }
        }

        replace(dist.begin(), dist.end(), INT_MAX, -1);

        return dist;
    }
};