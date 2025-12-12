// https://leetcode.com/problems/maximum-number-of-k-divisible-components
// 2025/11/28

class Solution {
    pair<int, int> dfs(const vector<vector<int>>& graph, const vector<int>& values, int k, int curr, int prev) {
        int val = values[curr] % k, count = 0;
        for (const int next : graph[curr]) {
            if (next == prev) continue;

            const auto [v, c] = dfs(graph, values, k, next, curr);
            val = (val + v) % k;
            count += c;
        }

        return {val, count + (val == 0)};
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        return dfs(graph, values, k, 0, 0).second;
    }
};