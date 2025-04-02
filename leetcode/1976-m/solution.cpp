// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination
// 2025/03/23

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& r : roads) {
            graph[r[0]].emplace_back(r[1], r[2]);
            graph[r[1]].emplace_back(r[0], r[2]);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);

        vector<long long> dist(n, LONG_LONG_MAX);
        dist[0] = 0;

        vector<int> ways(n);
        ways[0] = 1;

        while (!pq.empty()) {
            const auto [w, v] = pq.top();
            pq.pop();

            if (w > dist[v]) continue;

            for (const auto [nv, nw] : graph[v]) {
                const long long d = w + nw;

                if (d > dist[nv]) continue;

                if (d == dist[nv]) {
                    ways[nv] = (ways[nv] + ways[v]) % 1'000'000'007;
                } else {
                    dist[nv] = d;
                    ways[nv] = ways[v];
                    pq.emplace(d, nv);
                }
            }
        }

        return ways.back();
    }
};