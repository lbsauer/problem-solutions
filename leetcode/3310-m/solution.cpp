// https://leetcode.com/problems/remove-methods-from-project
// 2024-11-14

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for (const auto& i : invocations) {
            graph[i[0]].push_back(i[1]);
        }

        vector<bool> visited(n);
        visited[k] = true;
        
        vector<int> stack{k};
        while (!stack.empty()) {
            const int u = stack.back();
            stack.pop_back();

            for (const int v : graph[u]) {
                if (visited[v]) continue;

                visited[v] = true;
                stack.push_back(v);
            }
        }

        bool flag = false;
        for (const auto& i : invocations) {
            if (flag = visited[i[0]] != visited[i[1]]) break;
        }

        if (flag) {
            stack.resize(n);
            iota(stack.begin(), stack.end(), 0);
        } else {
            for (int i = 0, j = 0; i < n; ++i) {
                if (!visited[i]) stack.push_back(i);
            }
        }

        return stack;
    }
};