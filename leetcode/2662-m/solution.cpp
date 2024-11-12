// https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads
// 2024-11-12

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        specialRoads.resize(1 + distance(
            specialRoads.begin(),
            copy_if(specialRoads.begin(), specialRoads.end(), specialRoads.begin(), [](const auto& r) {
                return r[4] < abs(r[0] - r[2]) + abs(r[1] - r[3]);
            })
        ));
        specialRoads.back() = {0, 0, start[0], start[1], 0};
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, specialRoads.size() - 1);

        vector<int> dist(specialRoads.size() + 1, INT_MAX);
        dist.back() = 0;

        int min_cost = abs(start[0] - target[0]) + abs(start[1] - target[1]);

        while (!pq.empty()) {
            const auto [w, idx] = pq.top();
            pq.pop();

            if (w > min(dist[idx], min_cost)) continue;

            const int x = specialRoads[idx][2];
            const int y = specialRoads[idx][3];

            min_cost = min(min_cost, abs(x - target[0]) + abs(y - target[1]) + w);

            for (int i = 0; const auto& r : specialRoads) {
                int new_dist = abs(r[0] - x) + abs(r[1] - y) + r[4] + w;

                if (new_dist < dist[i]) {
                    dist[i] = new_dist;
                    pq.emplace(new_dist, i);
                }

                ++i;
            }
        }

        return min_cost;
    }
};