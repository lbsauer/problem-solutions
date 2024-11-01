// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
// 2024/07/26

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1'000'000));

        for (const auto& e : edges) {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
            
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }

        int res = 0;
        int min_count = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j || dist[i][j] > distanceThreshold) continue;

                ++count;
            }

            if (count > min_count) continue;

            min_count = count;
            res = i;
        }

        return res;
    }
};