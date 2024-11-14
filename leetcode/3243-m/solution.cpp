// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i
// 2024-11-13

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; ++i) {
            graph[i].push_back(i + 1);
        }

        vector<int> dist(n);
        iota(dist.begin(), dist.end(), 0);

        vector<int> res(queries.size());
        vector<int> stack;

        for (auto it = res.begin(); const auto& qr : queries) {
            graph[qr[0]].push_back(qr[1]);

            dist[qr[1]] = min(dist[qr[1]], dist[qr[0]] + 1);

            stack.push_back(qr[1]);
            while (!stack.empty()) {
                const int u = stack.back();
                stack.pop_back();

                for (const int v : graph[u]) {
                    if (dist[v] <= dist[u] + 1) continue;

                    dist[v] = dist[u] + 1;
                    stack.push_back(v);
                }
            }

            *it++ = dist.back();
        }

        return res;
    }
};