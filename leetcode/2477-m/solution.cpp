// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital
// 2024/11/12

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> graph(roads.size() + 1);
        vector<int> degree(graph.size());
        for (const auto& r : roads) {
            graph[r[0]].push_back(r[1]);
            graph[r[1]].push_back(r[0]);

            ++degree[r[0]];
            ++degree[r[1]];
        }

        degree[0] = INT_MAX;

        long long cost = 0;
        vector<int> rep(graph.size(), 1);

        deque<int> q;
        for (int i = 1; i < degree.size(); ++i) {
            if (degree[i] == 1) q.push_back(i);
        }

        while (!q.empty()) {
            const int u = q.front();
            q.pop_front();

            cost += (rep[u] + seats - 1) / seats;

            for (const int v : graph[u]) {
                if (--degree[v] == 1) q.push_back(v);

                rep[v] += rep[u];
            }
        }

        return cost;
    }
};