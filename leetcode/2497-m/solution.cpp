// https://leetcode.com/problems/maximum-star-sum-of-a-graph
// 2024-11-05

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        if (k == 0) return *max_element(vals.begin(), vals.end());
        
        vector<vector<int>> graph(vals.size());
        for (const auto& e : edges) {
            if (vals[e[1]] > 0) graph[e[0]].push_back(vals[e[1]]);
            if (vals[e[0]] > 0) graph[e[1]].push_back(vals[e[0]]);
        }

        int sum = INT_MIN;
        for (auto it = vals.begin(); auto& e : graph) {
            partial_sort(e.begin(), e.begin() + min(size_t(k), e.size()), e.end(), greater<int>{});

            sum = max(sum, accumulate(e.begin(), e.begin() + min(size_t(k), e.size()), *it++));
        }

        return sum;
    }
};