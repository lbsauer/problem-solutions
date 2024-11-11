// https://leetcode.com/problems/node-with-highest-edge-score
// 2024-11-11

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long> scores(edges.size());
        for (int i = 1; i < edges.size(); ++i) {
            scores[edges[i]] += i;
        }

        return distance(scores.begin(), max_element(scores.begin(), scores.end()));
    }
};