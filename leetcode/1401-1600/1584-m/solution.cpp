// https://leetcode.com/problems/min-cost-to-connect-all-points
// 2024/08/05

class Solution {
public:
    struct Edge {
        int v, w;

        bool operator<(const Edge& r) const {
            return w > r.w;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<Edge> pq;
        for (int i = 1; i < points.size(); ++i) {
            pq.push({
                i,
                abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1])
            });
        }

        vector<bool> visited(points.size());
        visited[0] = true;

        int cost = 0;

        int count = 1;
        while (count < points.size()) {
            const Edge curr = pq.top();
            pq.pop();

            if (visited[curr.v]) continue;

            visited[curr.v] = true;
            cost += curr.w;
            ++count;

            for (int i = 0; i < points.size(); ++i) {
                if (visited[i]) continue;

                pq.push({
                    i,
                    abs(points[i][0] - points[curr.v][0]) + abs(points[i][1] - points[curr.v][1])
                });
            }
        }

        return cost;
    }
};