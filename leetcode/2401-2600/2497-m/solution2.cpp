// https://leetcode.com/problems/maximum-star-sum-of-a-graph
// 2024/11/05

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        if (k == 0) return *max_element(vals.begin(), vals.end());
        
        vector<priority_queue<int, vector<int>, greater<int>>> graph(vals.size());
        for (const auto& e : edges) {
            if (vals[e[1]] > 0) graph[e[0]].push(vals[e[1]]);
            if (graph[e[0]].size() > k) graph[e[0]].pop();

            if (vals[e[0]] > 0) graph[e[1]].push(vals[e[0]]);
            if (graph[e[1]].size() > k) graph[e[1]].pop();
        }

        int sum = INT_MIN;
        for (auto it = vals.begin(); auto& pq : graph) {
            int curr = *it++;

            while (!pq.empty()) {
                curr += pq.top();
                pq.pop();
            }

            sum = max(sum, curr);
        }

        return sum;
    }
};