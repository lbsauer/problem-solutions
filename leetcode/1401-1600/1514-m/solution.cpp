// https://leetcode.com/problems/path-with-maximum-probability
// 2024/08/27

class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, double>& lhs, const pair<int, double>& rhs) {
            return lhs.second < rhs.second;
        }
    };
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        priority_queue<pair<int, double>, vector<pair<int, double>>, Compare> pq;
        pq.emplace(start_node, 1);

        vector<double> probability(n, 0);
        probability[start_node] = 1;

        vector<bool> visited(n);

        while (!pq.empty()) {
            const auto [curr, prob] = pq.top();
            pq.pop();

            if (visited[curr]) continue;

            visited[curr] = true;

            for (const auto [v, p] : graph[curr]) {
                if (visited[v]) continue;

                double new_prob = prob * p;

                if (new_prob > probability[v]) {
                    probability[v] = new_prob;
                    pq.emplace(v, new_prob);
                }
            }
        }

        return probability[end_node];
    }
};