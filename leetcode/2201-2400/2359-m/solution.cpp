// https://leetcode.com/problems/find-closest-node-to-given-two-nodes
// 2024/11/11

class Solution {
    vector<int> distance_from(const vector<int>& edges, int u) {
        vector<int> dist(edges.size(), INT_MAX);
        for (int i = 0; u != -1 && dist[u] == INT_MAX; ++i) {
            dist[u] = i;
            u = edges[u];
        }

        return dist;
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const vector<int> dist1 = distance_from(edges, node1);
        const vector<int> dist2 = distance_from(edges, node2);

        int closest = -1, min_dist = INT_MAX;
        for (int i = 0; i < edges.size(); ++i) {
            const int d = max(dist1[i], dist2[i]);
            if (d < min_dist) {
                min_dist = d;
                closest = i;
            }
        }

        return closest;
    }
};