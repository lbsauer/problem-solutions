// https://leetcode.com/problems/detonate-the-maximum-bombs
// 2024-11-09

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> graph(bombs.size());
        for (int i = 0; i < bombs.size(); ++i) {
            long long x = bombs[i][0];
            long long y = bombs[i][1];
            long long ri = bombs[i][2];

            for (int j = i + 1; j < bombs.size(); ++j) {
                long long dx = bombs[j][0] - x;
                long long dy = bombs[j][1] - y;
                long long rj = bombs[j][2];

                if (dx * dx + dy * dy <= ri * ri) graph[i].push_back(j);
                if (dx * dx + dy * dy <= rj * rj) graph[j].push_back(i);
            }
        }

        int res = 0;

        for (int i = 0; i < graph.size() && res != graph.size(); ++i) {
            vector<bool> visited(graph.size());
            visited[i] = true;

            int count = 1;

            deque<int> stack{i};
            while (!stack.empty()) {
                const int u = stack.back();
                stack.pop_back();

                for (const int v : graph[u]) {
                    if (visited[v]) continue;

                    ++count;

                    visited[v] = true;
                    stack.push_back(v);
                }
            }

            res = max(res, count);
        }

        return res;
    }
};