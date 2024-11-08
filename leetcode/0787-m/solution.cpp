// https://leetcode.com/problems/cheapest-flights-within-k-stops
// 2024-11-06

class Solution {
    struct Edge { int v, w, s; };
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (const vector<int>& f : flights) {
            if (f[1] == src) continue;

            graph[f[0]].emplace_back(f[1], f[2]);
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        deque<Edge> q{{src, 0, 0}};
        while (!q.empty()) {
            const Edge curr = q.front();
            q.pop_front();

            if (curr.s > k) continue;

            for (const auto [v, w] : graph[curr.v]) {
                int new_dist = curr.w + w;

                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    q.push_back({v, new_dist, curr.s + 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};