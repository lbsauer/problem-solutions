// https://leetcode.com/problems/most-profitable-path-in-a-tree
// 2024/11/11

class Solution {
    int bob_dfs(vector<vector<int>>& graph, vector<int>& dist, int u, int parent) {
        for (const int v : graph[u]) {
            if (v == parent) continue;

            dist[u] = min(dist[u], bob_dfs(graph, dist, v, u) + 1);
        }

        return dist[u] == INT_MAX ? INT_MAX - 1 : dist[u];
    }

    void alice_dfs(vector<vector<int>>& graph, vector<int>& dist, vector<int>& profit, vector<int>& amount, int u, int d, int parent) {
        profit[u] = profit[parent] + (d > dist[u] ? 0 : amount[u] >> (d == dist[u]));
        
        for (const int v : graph[u]) {
            if (v == parent) continue;

            alice_dfs(graph, dist, profit, amount, v, d + 1, u);
        }
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> graph(amount.size());
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> dist(graph.size(), INT_MAX);
        dist[bob] = 0;

        bob_dfs(graph, dist, 0, 0);

        vector<int> profit(graph.size());

        alice_dfs(graph, dist, profit, amount, 0, 0, 0);

        int res = INT_MIN;
        for (int i = 1; i < profit.size(); ++i) {
            res = graph[i].size() > 1 ? res : max(res, profit[i]);
        }

        return res;
    }
};