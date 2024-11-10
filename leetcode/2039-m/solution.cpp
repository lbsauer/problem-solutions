// https://leetcode.com/problems/the-time-when-the-network-becomes-idle
// 2024-11-09

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        vector<vector<int>> graph(patience.size());
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        patience[0] = 1;

        int d = 1;
        int idle = 0;

        vector<bool> visited(graph.size());
        visited[0] = true;

        deque<int> q{0};

        for (int d = 0; !q.empty(); ++d) {
            int size = q.size();

            while (size-- > 0) {
                const int u = q.front();
                q.pop_front();

                for (const int v : graph[u]) {
                    if (visited[v]) continue;

                    visited[v] = true;
                    q.push_back(v);
                }

                idle = max(idle, (2 * d - 1) / patience[u] * patience[u] + 2 * d);
            }
        }

        return idle + 1;
    }
};