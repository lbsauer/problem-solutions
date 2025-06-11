// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs
// 2025/04/24

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (const auto& p : adjacentPairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        auto& [first, next] = *find_if(adj.begin(), adj.end(), [](const auto& l) { return l.second.size() == 1; });

        vector<int> res(adjacentPairs.size() + 1);
        for (int i = 0, prev = INT_MAX, curr = first; i < res.size(); ++i) {
            res[i] = curr;
            curr = next.front() == prev ? next.back() : next.front();
            prev = res[i];
            next = adj[curr];
        }

        return res;
    }
};