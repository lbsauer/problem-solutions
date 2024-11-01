// https://leetcode.com/problems/find-if-path-exists-in-graph
// 2024/07/25

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        stack<int> stack;
        stack.push(source);

        vector<bool> visited(n);
        visited[source] = true;

        while (!stack.empty()) {
            const int v = stack.top();
            stack.pop();

            if (v == destination) return true;

            for (const int u : graph[v]) {
                if (visited[u]) continue;

                stack.push(u);
                visited[u] = true;
            }
        }

        return false;
    }
};