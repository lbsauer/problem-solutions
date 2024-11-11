// https://leetcode.com/problems/longest-cycle-in-a-graph
// 2024-11-11

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<int> parent(edges.size(), INT_MAX);
        vector<int> dist(edges.size());

        int res = -1;

        for (int i = 0; i < edges.size(); ++i) {
            if (parent[i] != INT_MAX) continue;

            for (int d = 0, curr = i; curr != -1; ++d) {                
                res = parent[curr] == i ? max(res, d - dist[curr]) : res;
                
                if (parent[curr] != INT_MAX) break;

                parent[curr] = i;
                dist[curr] = d;
                curr = edges[curr];
            }
        }

        return res;
    }
};