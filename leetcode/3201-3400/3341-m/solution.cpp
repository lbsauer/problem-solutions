// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i
// 2024/11/14

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        const int n = moveTime.size(), m = moveTime.front().size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        deque<pair<int, int>> q{{0, 0}};

        while (!q.empty()) {
            const auto [x, y] = q.front();
            q.pop_front();

            const int w = dist[x][y];

            for (auto [nx, ny] : directions) {
                nx += x;
                ny += y;

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                const int d = max(w, moveTime[nx][ny]) + 1;
                
                if (d < dist[nx][ny]) {
                    dist[nx][ny] = d;
                    q.emplace_back(nx, ny);
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};