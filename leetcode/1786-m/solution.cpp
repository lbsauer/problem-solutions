// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node
// 2024/08/11

class Solution {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, src);

        vector<int> dist(graph.size(), INT_MAX);
        dist[src] = 0;

        while (!pq.empty()) {
            const auto [w, v] = pq.top();
            pq.pop();

            if (w > dist[v]) continue;

            for (const auto [nw, nv] : graph[v]) {
                int new_dist = w + nw;

                if (new_dist < dist[nv]) {
                    dist[nv] = new_dist;
                    pq.emplace(new_dist, nv);
                }
            }
        }

        return dist;
    }

    int dfs(vector<vector<pair<int, int>>>& graph, vector<int>& dist, vector<int>& paths, int u) {
        if (paths[u] != -1) return paths[u];

        paths[u] = 0;

        for (const auto [_, v] : graph[u]) {
            if (dist[u] >= dist[v]) continue;

            paths[u] = (paths[u] + dfs(graph, dist, paths, v)) % 1'000'000'007;
        }

        return paths[u];
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& e : edges) {
            graph[e[0] - 1].emplace_back(e[2], e[1] - 1);
            graph[e[1] - 1].emplace_back(e[2], e[0] - 1);
        }

        vector<int> dist(dijkstra(graph, n - 1));

        vector<int> paths(n, -1);
        paths.front() = 1;

        return dfs(graph, dist, paths, n - 1);
    }
};