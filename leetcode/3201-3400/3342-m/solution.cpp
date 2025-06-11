// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii
// 2024/11/24

class Solution {
    struct Point {
        int w, x, y;
        bool b;

        Point(int w, int x, int y, bool b) : w(w), x(x), y(y), b(b) {}

        bool operator<(const Point& other) const {
            return w > other.w;
        }
    };

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        constexpr static pair<int, int> directions[]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        const int n = moveTime.size(), m = moveTime.front().size();

        priority_queue<Point> pq;
        pq.emplace(0, 0, 0, false);

        while (!pq.empty()) {
            const auto [w, x, y, b] = pq.top();
            pq.pop();

            for (auto [nx, ny] : directions) {
                nx += x;
                ny += y;

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || moveTime[nx][ny] == -1) continue;

                const int nw = 1 + b + max(w, moveTime[nx][ny]);

                if (nx == n - 1 && ny == m - 1) return nw;

                pq.emplace(nw, nx, ny, !b);
                moveTime[nx][ny] = -1;
            }
        }

        return -1;
    }
};