// https://leetcode.com/problems/find-eventual-safe-states
// 2024/11/06

class Solution {
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& safe, int u) {
        if (visited[u]) return safe[u];

        visited[u] = true;

        for (const int v : graph[u]) {
            if (!dfs(graph, visited, safe, v)) return false;
        }

        return safe[u] = true;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size()), safe(graph.size());
        for (int i = 0; i < graph.size(); ++i) {
            visited[i] = safe[i] = graph[i].empty();
        }

        vector<int> res;
        for (int i = 0; i < graph.size(); ++i) {
            if (dfs(graph, visited, safe, i)) res.push_back(i);
        }

        return res;
    }
};