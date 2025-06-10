// https://leetcode.com/problems/is-graph-bipartite
// 2024/11/06

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size());
        vector<bool> color(graph.size());

        for (int i = 0; i < graph.size(); ++i) {
            if (visited[i]) continue;

            vector<int> stack{i};
            while (!stack.empty()) {
                const int u = stack.back();
                stack.pop_back();

                for (const int v : graph[u]) {
                    if (visited[v]) {
                        if (color[u] == color[v]) return false;
                    } else {
                        visited[v] = true;
                        color[v] = !color[u];

                        stack.push_back(v);
                    }
                }
            }
        }

        return true;
    }
};